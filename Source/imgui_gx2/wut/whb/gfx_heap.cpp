#include "imgui_gx2/wut/whb/gfx_heap.h"
#include "pe/Util/Log.h"

static void*
    sGfxHeapMEM1
    = NULL;

static void*
    sGfxHeapForeground
    = NULL;

#define GFX_FRAME_HEAP_TAG (0x123DECAF)

bool GfxHeapInitMEM1()
{
    MEMHeapHandle heap = MEMGetBaseHeapHandle(MEM_BASE_HEAP_MEM1);
    uint32_t size;
    void* base;

    if (!MEMRecordStateForFrmHeap(heap, GFX_FRAME_HEAP_TAG)) {
        PE_LOG("%s: MEMRecordStateForFrmHeap failed", __FUNCTION__);
        return false;
    }

    size = MEMGetAllocatableSizeForFrmHeapEx(heap, 4);
    if (!size) {
        PE_LOG("%s: MEMGetAllocatableSizeForFrmHeapEx == 0", __FUNCTION__);
        return false;
    }

    base = MEMAllocFromFrmHeapEx(heap, size, 4);
    if (!base) {
        PE_LOG("%s: MEMAllocFromFrmHeapEx(heap, 0x%X, 4) failed", __FUNCTION__, size);
        return false;
    }

    sGfxHeapMEM1 = MEMCreateExpHeapEx(base, size, 0);
    if (!sGfxHeapMEM1) {
        PE_LOG("%s: MEMCreateExpHeapEx(0x%08X, 0x%X, 0) failed", __FUNCTION__, base, size);
        return false;
    }

    return true;
}

bool GfxHeapDestroyMEM1()
{
    MEMHeapHandle heap = MEMGetBaseHeapHandle(MEM_BASE_HEAP_MEM1);

    if (sGfxHeapMEM1) {
        MEMDestroyExpHeap(sGfxHeapMEM1);
        sGfxHeapMEM1 = NULL;
    }

    MEMFreeByStateToFrmHeap(heap, GFX_FRAME_HEAP_TAG);
    return true;
}

bool GfxHeapInitForeground()
{
    MEMHeapHandle heap = MEMGetBaseHeapHandle(MEM_BASE_HEAP_FG);
    uint32_t size;
    void* base;

    size = MEMGetAllocatableSizeForFrmHeapEx(heap, 4);
    if (!size) {
        PE_LOG("%s: MEMAllocFromFrmHeapEx(heap, 0x%X, 4)", __FUNCTION__, size);
        return false;
    }

    base = MEMAllocFromFrmHeapEx(heap, size, 4);
    if (!base) {
        PE_LOG("%s: MEMGetAllocatableSizeForFrmHeapEx == 0", __FUNCTION__);
        return false;
    }

    sGfxHeapForeground = MEMCreateExpHeapEx(base, size, 0);
    if (!sGfxHeapForeground) {
        PE_LOG("%s: MEMCreateExpHeapEx(0x%08X, 0x%X, 0)", __FUNCTION__, base, size);
        return false;
    }

    return true;
}

bool GfxHeapDestroyForeground()
{
    MEMHeapHandle foreground = MEMGetBaseHeapHandle(MEM_BASE_HEAP_FG);

    if (sGfxHeapForeground) {
        MEMDestroyExpHeap(sGfxHeapForeground);
        sGfxHeapForeground = NULL;
    }

    MEMFreeToFrmHeap(foreground, MEM_FRM_HEAP_FREE_ALL);
    return true;
}

void* GfxHeapAllocMEM1(uint32_t size,
    uint32_t alignment)
{
    void* block;

    if (!sGfxHeapMEM1) {
        return NULL;
    }

    if (alignment < 4) {
        alignment = 4;
    }

    block = MEMAllocFromExpHeapEx(sGfxHeapMEM1, size, alignment);
    return block;
}

void GfxHeapFreeMEM1(void* block)
{
    if (!sGfxHeapMEM1) {
        return;
    }

    MEMFreeToExpHeap(sGfxHeapMEM1, block);
}

void* GfxHeapAllocForeground(uint32_t size,
    uint32_t alignment)
{
    void* block;

    if (!sGfxHeapForeground) {
        return NULL;
    }

    if (alignment < 4) {
        alignment = 4;
    }

    block = MEMAllocFromExpHeapEx(sGfxHeapForeground, size, alignment);
    return block;
}

void GfxHeapFreeForeground(void* block)
{
    if (!sGfxHeapForeground) {
        return;
    }

    MEMFreeToExpHeap(sGfxHeapForeground, block);
}

void* GfxHeapAllocMEM2(uint32_t size,
    uint32_t alignment)
{
    if (alignment < 4) {
        alignment = 4;
    }

    return MEMAllocFromDefaultHeapEx(size, alignment);
}

void GfxHeapFreeMEM2(void* block)
{
    MEMFreeToDefaultHeap(block);
}
