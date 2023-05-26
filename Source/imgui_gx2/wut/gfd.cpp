#include "imgui_gx2/wut/gfd.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// #define CHECK_GPU_VERSION

static uint32_t _GFDCleanTag(uint32_t tag);
static bool _GFDCheckTagDAT(uint32_t tag);
static bool _GFDCheckTagSTR(uint32_t tag);
static bool _GFDRelocateBlock(const GFDBlockHeader* blockHeader, void* dst);
static bool _GFDRelocateBlockEx(const GFDRelocationHeader* relocationHeader,
    const uint32_t* patchTable, uint8_t* dst);
static uint32_t _GFDGetBlockDataSize(GFDBlockType type, uint32_t index,
    const void* file);
static uint32_t _GFDGetBlockCount(GFDBlockType type, const void* file);
static bool _GFDCheckBlockHeaderMagicVersions(const GFDBlockHeader* header);
static bool _GFDCheckHeaderVersions(const void* file);
static bool _GFDGetHeaderVersions(uint32_t* majorVersion,
    uint32_t* minorVersion, uint32_t* gpuVersion,
    const void* file);
static bool _GFDGetBlockPointerConst(GFDBlockType type, uint32_t index,
    const void* file,
    const GFDBlockHeader** blockHeaderOut,
    const void** blockDataOut);
#if 0 // Currently unused
static bool _GFDGetBlockPointer(GFDBlockType type, uint32_t index, void *file,
                                GFDBlockHeader **blockHeaderOut,
                                void **blockDataOut);
#endif

static char
    sLastError[1024]
    = { 0 };

static void
setLastError(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vsnprintf(sLastError, 1024, fmt, va);
    va_end(va);
}

char* GFDGetLastErrorString()
{
    return sLastError;
}

static bool
_GFDGetHeaderVersions(uint32_t* majorVersion,
    uint32_t* minorVersion,
    uint32_t* gpuVersion,
    const void* file)
{
    GFDHeader* header = (GFDHeader*)file;
    *majorVersion = 0;
    *minorVersion = 0;
    *gpuVersion = 0;

    if (header->magic != GFD_HEADER_MAGIC) {
        setLastError("%s: header->magic %08X != %08X GFD_HEADER_MAGIC",
            __FUNCTION__, header->magic, GFD_HEADER_MAGIC);
        return false;
    }

    *majorVersion = header->majorVersion;
    *minorVersion = header->minorVersion;
    *gpuVersion = header->gpuVersion;
    return true;
}

static bool
_GFDCheckHeaderVersions(const void* file)
{
    uint32_t majorVersion, minorVersion, gpuVersion;

    if (!_GFDGetHeaderVersions(&majorVersion, &minorVersion, &gpuVersion, file)) {
        return false;
    }

    if (majorVersion != GFD_FILE_VERSION_MAJOR) {
        setLastError("%s: majorVersion %d != %d GFD_FILE_VERSION_MAJOR",
            __FUNCTION__, majorVersion, GFD_FILE_VERSION_MAJOR);
        return false;
    }

    if (minorVersion != GFD_FILE_VERSION_MINOR) {
        setLastError("%s: minorVersion %d != %d GFD_FILE_VERSION_MINOR",
            __FUNCTION__, minorVersion, GFD_FILE_VERSION_MINOR);
        return false;
    }

#ifdef CHECK_GPU_VERSION
    if (gpuVersion != GX2TempGetGPUVersion()) {
        setLastError("%s: gpuVersion %d != %d GX2TempGetGPUVersion()",
            __FUNCTION__, gpuVersion, GX2TempGetGPUVersion());
        return false;
    }
#endif

    return true;
}

static bool
_GFDCheckBlockHeaderMagicVersions(const GFDBlockHeader* header)
{
    if (header->magic != GFD_BLOCK_HEADER_MAGIC) {
        setLastError("%s: header->magic %08X != GFD_BLOCK_HEADER_MAGIC",
            __FUNCTION__, header->magic);
        return false;
    }

    if (header->majorVersion != GFD_BLOCK_VERSION_MAJOR) {
        setLastError("%s: header->majorVersion %d != GFD_BLOCK_VERSION_MAJOR",
            __FUNCTION__, header->majorVersion);
        return false;
    }

    return true;
}

static uint32_t
_GFDGetBlockCount(GFDBlockType type,
    const void* file)
{
    const uint8_t* ptr = (const uint8_t*)file;
    const GFDHeader* fileHeader = (const GFDHeader*)file;
    const GFDBlockHeader* blockHeader;
    uint32_t count = 0;

    if (!file) {
        return 0;
    }

    if (!_GFDCheckHeaderVersions(file)) {
        return 0;
    }

    ptr += fileHeader->headerSize;
    blockHeader = (const GFDBlockHeader*)ptr;

    while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
        if (blockHeader->type == type) {
            count++;
        } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
            break;
        }

        ptr += blockHeader->headerSize + blockHeader->dataSize;
        blockHeader = (const GFDBlockHeader*)ptr;
    }

    return count;
}

static uint32_t
_GFDGetBlockDataSize(GFDBlockType type,
    uint32_t index,
    const void* file)
{
    const uint8_t* ptr = (const uint8_t*)file;
    const GFDHeader* fileHeader = (const GFDHeader*)file;
    const GFDBlockHeader* blockHeader;
    uint32_t count = 0;

    if (!file) {
        return 0;
    }

    if (!_GFDCheckHeaderVersions(file)) {
        return 0;
    }

    ptr += fileHeader->headerSize;
    blockHeader = (const GFDBlockHeader*)ptr;

    while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
        if (blockHeader->type == type) {
            if (count == index) {
                return blockHeader->dataSize;
            }

            count++;
        } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
            break;
        }

        ptr += blockHeader->headerSize + blockHeader->dataSize;
        blockHeader = (const GFDBlockHeader*)ptr;
    }

    return 0;
}

static bool
_GFDGetBlockPointerConst(GFDBlockType type,
    uint32_t index,
    const void* file,
    const GFDBlockHeader** blockHeaderOut,
    const void** blockDataOut)
{
    const uint8_t* ptr = (const uint8_t*)file;
    const GFDHeader* fileHeader = (const GFDHeader*)file;
    const GFDBlockHeader* blockHeader;
    uint32_t count = 0;

    if (!file) {
        return false;
    }

    if (!_GFDCheckHeaderVersions(file)) {
        return false;
    }

    ptr += fileHeader->headerSize;
    blockHeader = (const GFDBlockHeader*)ptr;

    while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
        if (blockHeader->type == type) {
            if (count == index) {
                *blockHeaderOut = blockHeader;
                *blockDataOut = ptr + blockHeader->headerSize;
                return true;
            }

            count++;
        } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
            break;
        }

        ptr += blockHeader->headerSize + blockHeader->dataSize;
        blockHeader = (const GFDBlockHeader*)ptr;
    }

    return false;
}

#if 0
static bool
_GFDGetBlockPointer(GFDBlockType type,
                    uint32_t index,
                    void *file,
                    GFDBlockHeader **blockHeaderOut,
                    void **blockDataOut)
{
   uint8_t *ptr = (uint8_t *)file;
   GFDHeader *fileHeader = (GFDHeader *)file;
   GFDBlockHeader *blockHeader;
   uint32_t count = 0;

   if (!file) {
      return false;
   }

   if (!_GFDCheckHeaderVersions(file)) {
      return false;
   }

   ptr += fileHeader->headerSize;
   blockHeader = (GFDBlockHeader *)ptr;

   while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
      if (blockHeader->type == type) {
         if (count == index) {
            *blockHeaderOut = blockHeader;
            *blockDataOut = ptr + blockHeader->headerSize;

            if (type == GFD_BLOCK_VERTEX_SHADER_HEADER
             || type == GFD_BLOCK_PIXEL_SHADER_HEADER
             || type == GFD_BLOCK_GEOMETRY_SHADER_HEADER
             || type == GFD_BLOCK_COMPUTE_SHADER_HEADER) {
               _GFDRelocateBlock(blockHeader, blockHeader);
            }

            return true;
         }

         count++;
      } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
         break;
      }

      ptr += blockHeader->headerSize + blockHeader->dataSize;
      blockHeader = (GFDBlockHeader *)ptr;
   }

   return false;
}
#endif

static uint32_t
_GFDCleanTag(uint32_t tag)
{
    return tag & ~GFD_PATCH_MASK;
}

static bool
_GFDCheckTagDAT(uint32_t tag)
{
    return (tag & GFD_PATCH_MASK) == GFD_PATCH_DATA;
}

static bool
_GFDCheckTagSTR(uint32_t tag)
{
    return (tag & GFD_PATCH_MASK) == GFD_PATCH_TEXT;
}

// This method differs from the official because they made poor design decisions.
static bool
_GFDRelocateBlockEx(const GFDRelocationHeader* relocationHeader,
    const uint32_t* patchTable,
    uint8_t* dst)
{
    uint32_t i;

    for (i = 0; i < relocationHeader->patchCount; ++i) {
        uint32_t* target;
        uint32_t offset = patchTable[i];

        if (offset == 0) {
            continue;
        }

        if (!_GFDCheckTagDAT(offset) && !_GFDCheckTagSTR(offset)) {
            setLastError("%s: !_GFDCheckTagDAT(offset = %08X) && "
                         "!_GFDCheckTagSTR(offset = %08X)",
                __FUNCTION__, offset, offset);
            return false;
        }

        target = (uint32_t*)(dst + _GFDCleanTag(offset));

        if (!_GFDCheckTagDAT(*target) && !_GFDCheckTagSTR(*target)) {
            setLastError("%s: !_GFDCheckTagDAT(*target = %08X) && "
                         "!_GFDCheckTagSTR(*target = %08X)",
                __FUNCTION__, *target, *target);
            return false;
        }

        *target = (uintptr_t)(dst + _GFDCleanTag(*target));
    }

    return true;
}

static bool
_GFDRelocateBlock(const GFDBlockHeader* blockHeader,
    void* dst)
{
    const uint8_t* blockData = ((const uint8_t*)blockHeader) + blockHeader->headerSize;
    const GFDRelocationHeader* relocationHeader;
    const uint32_t* patchTable;

    if (!blockHeader || !dst) {
        return false;
    }

    relocationHeader = (const GFDRelocationHeader*)(blockData
        + blockHeader->dataSize
        - sizeof(GFDRelocationHeader));

    if (relocationHeader->magic != GFD_RELOCATION_HEADER_MAGIC) {
        setLastError("%s: relocationHeader->magic %08X != GFD_RELOCATION_HEADER_MAGIC",
            __FUNCTION__, relocationHeader->magic);
        return false;
    }

    if (!_GFDCheckTagDAT(relocationHeader->patchOffset)) {
        setLastError("%s: !_GFDCheckTagDAT(relocationHeader->patchOffset = %08X)",
            __FUNCTION__, relocationHeader->patchOffset);
        return false;
    }

    patchTable = (const uint32_t*)(blockData + _GFDCleanTag(relocationHeader->patchOffset));
    return _GFDRelocateBlockEx(relocationHeader, patchTable, (uint8_t*)dst);
}

static bool
_GFDCheckShaderAlign(void* program)
{
    return (((uintptr_t)program) & (GX2_SHADER_PROGRAM_ALIGNMENT - 1)) == 0;
}

static bool
_GFDGetGenericBlock(GFDBlockType blockTypeHeader,
    void* header,
    GFDBlockType blockTypeProgram1,
    void** outProgramPtr1,
    void* program1,
    GFDBlockType blockTypeProgram2,
    void** outProgramPtr2,
    void* program2,
    uint32_t index,
    const void* file)
{
    const uint8_t* ptr = (const uint8_t*)file;
    const GFDHeader* fileHeader = (const GFDHeader*)file;
    const GFDBlockHeader* blockHeader;
    uint32_t headerCount = 0;
    uint32_t program1Count = 0;
    uint32_t program2Count = 0;
    bool result = false;

    if (!header || !file) {
        return false;
    }

    ptr += fileHeader->headerSize;
    blockHeader = (const GFDBlockHeader*)ptr;

    while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
        ptr += blockHeader->headerSize;

        if (blockHeader->type == blockTypeHeader) {
            if (headerCount == index) {
                memcpy(header, ptr, blockHeader->dataSize);

                // Process relocations for all headers except a texture header.
                if (blockTypeHeader != GFD_BLOCK_TEXTURE_HEADER) {
                    if (!_GFDRelocateBlock(blockHeader, header)) {
                        return false;
                    }
                }
            }

            headerCount++;
        } else if (blockHeader->type == blockTypeProgram1) {
            if (program1Count == index) {
                *outProgramPtr1 = program1;
                memcpy(program1, ptr, blockHeader->dataSize);
            }

            program1Count++;
        } else if (program2 && blockHeader->type == blockTypeProgram2) {
            if (program2Count == index) {
                *outProgramPtr2 = program2;
                memcpy(program2, ptr, blockHeader->dataSize);
            }

            program2Count++;
        } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
            break;
        }

        if (headerCount > index && program1Count > index) {
            if (!program2 || program2Count > index) {
                result = true;
                break;
            }
        }

        ptr += blockHeader->dataSize;
        blockHeader = (const GFDBlockHeader*)ptr;
    }

    return result;
}
/*
bool
GFDGetVertexShader(GX2VertexShader *shader,
                   void *program,
                   uint32_t index,
                   const void *file)
{
   const uint8_t *ptr = (const uint8_t *)file;
   const GFDHeader *fileHeader = (const GFDHeader *)file;
   const GFDBlockHeader *blockHeader;
   uint32_t headerCount = 0;
   uint32_t programCount = 0;
   bool result = false;

   if (!shader || !program || !file) {
      return false;
   }

   if ((uintptr_t)program & (GX2_SHADER_PROGRAM_ALIGNMENT - 1)) {
      return false;
   }

   ptr += fileHeader->headerSize;
   blockHeader = (const GFDBlockHeader *)ptr;

   while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
      ptr += blockHeader->headerSize;

      if (blockHeader->type == GFD_BLOCK_VERTEX_SHADER_HEADER) {
         if (headerCount == index) {
            if (blockHeader->dataSize < sizeof(GX2VertexShader)) {
               return false;
            }

            memcpy(shader, ptr, sizeof(GX2VertexShader));

            if (!_GFDRelocateBlock(blockHeader, shader)) {
               return false;
            }
         }

         headerCount++;
      } else if (blockHeader->type == GFD_BLOCK_VERTEX_SHADER_PROGRAM) {
         if (programCount == index) {
            shader->program = program;
            memcpy(program, ptr, blockHeader->dataSize);
         }

         programCount++;
      } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
         break;
      }

      if (headerCount > index && programCount > index) {
         result = true;
         break;
      }

      ptr += blockHeader->dataSize;
      blockHeader = (const GFDBlockHeader *)ptr;
   }

   return result;
}
*/

uint32_t
GFDGetComputeShaderCount(const void* file)
{
    return _GFDGetBlockCount(GFD_BLOCK_COMPUTE_SHADER_HEADER,
        file);
}

uint32_t
GFDGetComputeShaderHeaderSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_COMPUTE_SHADER_HEADER,
        index,
        file);
}

uint32_t
GFDGetComputeShaderProgramSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_COMPUTE_SHADER_PROGRAM,
        index,
        file);
}

/*
bool
GFDGetComputeShader(GX2ComputeShader *shader,
                    void *program,
                    uint32_t index,
                    const void *file)
{
   return _GFDGetGenericBlock(GFD_BLOCK_COMPUTE_SHADER_HEADER,
                              shader,
                              GFD_BLOCK_COMPUTE_SHADER_PROGRAM,
                              &shader->program,
                              program,
                              0,
                              NULL,
                              NULL,
                              index,
                              file);
}
*/

uint32_t
GFDGetGeometryShaderCount(const void* file)
{
    return _GFDGetBlockCount(GFD_BLOCK_GEOMETRY_SHADER_HEADER,
        file);
}

uint32_t
GFDGetGeometryShaderHeaderSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_GEOMETRY_SHADER_HEADER,
        index,
        file);
}

uint32_t
GFDGetGeometryShaderProgramSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_GEOMETRY_SHADER_PROGRAM,
        index,
        file);
}

uint32_t
GFDGetGeometryShaderCopyProgramSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_GEOMETRY_SHADER_COPY_PROGRAM,
        index,
        file);
}

bool GFDGetGeometryShader(GX2GeometryShader* shader,
    void* program,
    void* copyProgram,
    uint32_t index,
    const void* file)
{
    if (!_GFDCheckShaderAlign(program) || !_GFDCheckShaderAlign(copyProgram)) {
        return false;
    }

    return _GFDGetGenericBlock(GFD_BLOCK_GEOMETRY_SHADER_HEADER,
        shader,
        GFD_BLOCK_GEOMETRY_SHADER_PROGRAM,
        &shader->shaderData,
        program,
        GFD_BLOCK_GEOMETRY_SHADER_COPY_PROGRAM,
        &shader->vertexShaderData,
        copyProgram,
        index,
        file);
}

uint32_t
GFDGetPixelShaderCount(const void* file)
{
    return _GFDGetBlockCount(GFD_BLOCK_PIXEL_SHADER_HEADER,
        file);
}

uint32_t
GFDGetPixelShaderHeaderSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_PIXEL_SHADER_HEADER,
        index,
        file);
}

uint32_t
GFDGetPixelShaderProgramSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_PIXEL_SHADER_PROGRAM,
        index,
        file);
}

bool GFDGetPixelShader(GX2PixelShader* shader,
    void* program,
    uint32_t index,
    const void* file)
{
    if (!_GFDCheckShaderAlign(program)) {
        return false;
    }

    return _GFDGetGenericBlock(GFD_BLOCK_PIXEL_SHADER_HEADER,
        shader,
        GFD_BLOCK_PIXEL_SHADER_PROGRAM,
        &shader->shaderData,
        program,
        (GFDBlockType)0,
        NULL,
        NULL,
        index,
        file);
}

uint32_t
GFDGetVertexShaderCount(const void* file)
{
    return _GFDGetBlockCount(GFD_BLOCK_VERTEX_SHADER_HEADER,
        file);
}

uint32_t
GFDGetVertexShaderHeaderSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_VERTEX_SHADER_HEADER,
        index,
        file);
}

uint32_t
GFDGetVertexShaderProgramSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_VERTEX_SHADER_PROGRAM,
        index,
        file);
}

bool GFDGetVertexShader(GX2VertexShader* shader,
    void* program,
    uint32_t index,
    const void* file)
{
    return _GFDGetGenericBlock(GFD_BLOCK_VERTEX_SHADER_HEADER,
        shader,
        GFD_BLOCK_VERTEX_SHADER_PROGRAM,
        &shader->shaderData,
        program,
        (GFDBlockType)0,
        NULL,
        NULL,
        index,
        file);
}

uint32_t
GFDGetTextureCount(const void* file)
{
    return _GFDGetBlockCount(GFD_BLOCK_TEXTURE_HEADER,
        file);
}

uint32_t
GFDGetTextureHeaderSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_TEXTURE_HEADER,
        index,
        file);
}

uint32_t
GFDGetTextureImageSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_TEXTURE_IMAGE,
        index,
        file);
}

uint32_t
GFDGetTextureMipImageSize(uint32_t index,
    const void* file)
{
    return _GFDGetBlockDataSize(GFD_BLOCK_TEXTURE_MIPMAP,
        index,
        file);
}

uint32_t
GFDGetTextureAlignmentSize(uint32_t index,
    const void* file)
{
    const GFDBlockHeader* blockHeader;
    const GX2Texture* texture;

    if (!_GFDGetBlockPointerConst(GFD_BLOCK_TEXTURE_HEADER,
            index,
            file,
            &blockHeader,
            (const void**)&texture)) {
        return 0;
    }

    return texture->surface.align;
}

bool GFDGetTexture(GX2Texture* texture,
    void* image,
    void* mipmap,
    uint32_t index,
    const void* file)
{
    return _GFDGetGenericBlock(GFD_BLOCK_TEXTURE_HEADER,
        texture,
        GFD_BLOCK_TEXTURE_IMAGE,
        &texture->surface.imageData,
        image,
        GFD_BLOCK_TEXTURE_MIPMAP,
        &texture->surface.mipData,
        mipmap,
        index,
        file);
}

bool GFDGetGX2RTexture(GX2Texture* texture,
    uint32_t index,
    const void* file)
{
    const uint8_t* ptr = (const uint8_t*)file;
    const GFDHeader* fileHeader = (const GFDHeader*)file;
    const GFDBlockHeader* blockHeader;
    uint32_t headerCount = 0;
    bool created = false;

    if (!texture || !file) {
        return false;
    }

    ptr += fileHeader->headerSize;
    blockHeader = (const GFDBlockHeader*)ptr;

    while (_GFDCheckBlockHeaderMagicVersions(blockHeader)) {
        ptr += blockHeader->headerSize;

        if (blockHeader->type == GFD_BLOCK_TEXTURE_HEADER) {
            if (headerCount == index) {
                if (blockHeader->dataSize < sizeof(GX2Texture)) {
                    goto error;
                }

                memcpy(texture, ptr, sizeof(GX2Texture));

                texture->surface.imageData = NULL;
                texture->surface.mipData = NULL;

                GX2RCreateSurface(&texture->surface,
                    GX2R_RESOURCE_BIND_TEXTURE
                        | GX2R_RESOURCE_USAGE_CPU_READ
                        | GX2R_RESOURCE_USAGE_CPU_WRITE
                        | GX2R_RESOURCE_USAGE_GPU_READ);

                created = true;
            } else if (created) {
                break;
            }

            headerCount++;
        } else if (blockHeader->type == GFD_BLOCK_TEXTURE_IMAGE) {
            if (created) {
                void* image = GX2RLockSurfaceEx(&texture->surface, 0, 0);
                if (!image) {
                    goto error;
                }

                memcpy(image, ptr, blockHeader->dataSize);
                GX2RUnlockSurfaceEx(&texture->surface, 0,
                    GX2R_RESOURCE_DISABLE_CPU_INVALIDATE
                        | GX2R_RESOURCE_DISABLE_GPU_INVALIDATE);
            }
        } else if (blockHeader->type == GFD_BLOCK_TEXTURE_MIPMAP) {
            if (created) {
                void* mipmap = GX2RLockSurfaceEx(&texture->surface, -1, 0);
                if (!mipmap) {
                    goto error;
                }

                memcpy(mipmap, ptr, blockHeader->dataSize);
                GX2RUnlockSurfaceEx(&texture->surface, -1,
                    GX2R_RESOURCE_DISABLE_CPU_INVALIDATE
                        | GX2R_RESOURCE_DISABLE_GPU_INVALIDATE);
            }
        } else if (blockHeader->type == GFD_BLOCK_END_OF_FILE) {
            break;
        }

        ptr += blockHeader->dataSize;
        blockHeader = (const GFDBlockHeader*)ptr;
    }

    if (created && (texture->surface.imageData || texture->surface.mipData)) {
        if (texture->surface.imageData) {
            GX2RInvalidateSurface(&texture->surface, 0, 0);
        }

        if (texture->surface.mipData) {
            GX2RInvalidateSurface(&texture->surface, -1, 0);
        }

        return true;
    }

error:
    GX2RDestroySurfaceEx(&texture->surface, 0);
    return false;
}

const GX2Texture*
GFDGetTexturePointer(uint32_t index,
    const void* file)
{
    const GFDBlockHeader* blockHeader;
    const GX2Texture* texture;

    if (!_GFDGetBlockPointerConst(GFD_BLOCK_TEXTURE_HEADER,
            index,
            file,
            &blockHeader,
            (const void**)&texture)) {
        return NULL;
    }

    if (blockHeader->dataSize < sizeof(GX2Texture)) {
        return NULL;
    }

    return texture;
}
