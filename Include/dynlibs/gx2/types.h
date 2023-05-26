/****************************************************************************
 * Copyright (C) 2015
 * by Dimok
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 * must not claim that you wrote the original software. If you use
 * this software in a product, an acknowledgment in the product
 * documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 ***************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "dynlibs/os/types.h"

//!-----------------------------------------------------------------------------------------------------------------------
//! Constants
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_COMMAND_BUFFER_SIZE 0x400000
#define GX2_COMMAND_BUFFER_ALIGNMENT 0x40
#define GX2_SCAN_BUFFER_ALIGNMENT 0x1000
#define GX2_SHADER_ALIGNMENT 0x100
#define GX2_CONTEXT_STATE_ALIGNMENT 0x100
#define GX2_DISPLAY_LIST_ALIGNMENT 0x20
#define GX2_VERTEX_BUFFER_ALIGNMENT 0x40
#define GX2_SHADER_PROGRAM_ALIGNMENT (0x100)
#define GX2_INDEX_BUFFER_ALIGNMENT 0x20

#define GX2_CONTEXT_STATE_SIZE 0xA100

#define GX2_AUX_BUFFER_CLEAR_VALUE 0xCC

//!-----------------------------------------------------------------------------------------------------------------------
//! Common
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_FALSE 0
#define GX2_TRUE 1
#define GX2_DISABLE 0
#define GX2_ENABLE 1

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2InitAttrib
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_INIT_ATTRIB_NULL 0
#define GX2_INIT_ATTRIB_CB_BASE 1
#define GX2_INIT_ATTRIB_CB_SIZE 2
#define GX2_INIT_ATTRIB_ARGC 7
#define GX2_INIT_ATTRIB_ARGV 8

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 compare functions
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_COMPARE_NEVER 0
#define GX2_COMPARE_LESS 1
#define GX2_COMPARE_EQUAL 2
#define GX2_COMPARE_LEQUAL 3
#define GX2_COMPARE_GREATER 4
#define GX2_COMPARE_NOTEQUAL 5
#define GX2_COMPARE_GEQUAL 6
#define GX2_COMPARE_ALWAYS 7

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 stencil functions
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_STENCIL_KEEP 0
#define GX2_STENCIL_ZERO 1
#define GX2_STENCIL_REPLACE 2
#define GX2_STENCIL_INCR 3
#define GX2_STENCIL_DECR 4
#define GX2_STENCIL_INVERT 5
#define GX2_STENCIL_INCR_WRAP 6
#define GX2_STENCIL_DECR_WRAP 7

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 logic op functions
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_LOGIC_OP_CLEAR 0x00
#define GX2_LOGIC_OP_NOR 0x11
#define GX2_LOGIC_OP_INVAND 0x22
#define GX2_LOGIC_OP_INVCOPY 0x33
#define GX2_LOGIC_OP_REVAND 0x44
#define GX2_LOGIC_OP_INV 0x55
#define GX2_LOGIC_OP_XOR 0x66
#define GX2_LOGIC_OP_NAND 0x77
#define GX2_LOGIC_OP_AND 0x88
#define GX2_LOGIC_OP_EQUIV 0x99
#define GX2_LOGIC_OP_NOOP 0xAA
#define GX2_LOGIC_OP_INVOR 0xBB
#define GX2_LOGIC_OP_COPY 0xCC
#define GX2_LOGIC_OP_REVOR 0xDD
#define GX2_LOGIC_OP_OR 0xEE
#define GX2_LOGIC_OP_SET 0xFF

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 blend combination functions
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_BLEND_COMBINE_ADD 0x00
#define GX2_BLEND_COMBINE_SRC_MINUS_DST 0x01
#define GX2_BLEND_COMBINE_MIN 0x02
#define GX2_BLEND_COMBINE_MAX 0x03
#define GX2_BLEND_COMBINE_DST_MINUS_SRC 0x04

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 blend functions
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_BLEND_ZERO 0x00
#define GX2_BLEND_ONE 0x01
#define GX2_BLEND_SRC_ALPHA 0x04
#define GX2_BLEND_ONE_MINUS_SRC_ALPHA 0x05

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 render targets
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_RENDER_TARGET_0 0
#define GX2_RENDER_TARGET_1 1
#define GX2_RENDER_TARGET_2 2
#define GX2_RENDER_TARGET_3 3
#define GX2_RENDER_TARGET_4 4
#define GX2_RENDER_TARGET_5 5
#define GX2_RENDER_TARGET_6 6
#define GX2_RENDER_TARGET_7 7

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 cull modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_FRONT_FACE_CCW 0
#define GX2_FRONT_FACE_CW 1
//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 polygon modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_POLYGON_MODE_POINT 0
#define GX2_POLYGON_MODE_LINE 1
#define GX2_POLYGON_MODE_TRIANGLE 2

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 special states
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SPECIAL_STATE_CLEAR 0
#define GX2_SPECIAL_STATE_CLEAR_HIZ 1
#define GX2_SPECIAL_STATE_COPY 2
#define GX2_SPECIAL_STATE_EXPAND_COLOR 3
#define GX2_SPECIAL_STATE_EXPAND_DEPTH 4
#define GX2_SPECIAL_STATE_CONVERT_DEPTH 5
#define GX2_SPECIAL_STATE_CONVERT_AADEPTH 6
#define GX2_SPECIAL_STATE_RESOLVE_COLOR 7
#define GX2_SPECIAL_STATE_CLEAR_COLOR_AS_DEPTH 8

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 attribute formats
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_ATTRIB_FORMAT_8_UNORM 0x00000000
#define GX2_ATTRIB_FORMAT_4_4_UNORM 0x00000001
#define GX2_ATTRIB_FORMAT_16_UNORM 0x00000002
#define GX2_ATTRIB_FORMAT_8_8_UNORM 0x00000004
#define GX2_ATTRIB_FORMAT_16_16_UNORM 0x00000007
#define GX2_ATTRIB_FORMAT_8_8_8_8_UNORM 0x0000000A
#define GX2_ATTRIB_FORMAT_10_10_10_2_UNORM 0x0000000B
#define GX2_ATTRIB_FORMAT_16_16_16_16_UNORM 0x0000000E

#define GX2_ATTRIB_FORMAT_8_UINT 0x00000100
#define GX2_ATTRIB_FORMAT_16_UINT 0x00000102
#define GX2_ATTRIB_FORMAT_8_8_UINT 0x00000104
#define GX2_ATTRIB_FORMAT_32_UINT 0x00000105
#define GX2_ATTRIB_FORMAT_16_16_UINT 0x00000107
#define GX2_ATTRIB_FORMAT_8_8_8_8_UINT 0x0000010A
#define GX2_ATTRIB_FORMAT_10_10_10_2_UINT 0x0000010B
#define GX2_ATTRIB_FORMAT_32_32_UINT 0x0000010C
#define GX2_ATTRIB_FORMAT_16_16_16_16_UINT 0x0000010E
#define GX2_ATTRIB_FORMAT_32_32_32_UINT 0x00000110
#define GX2_ATTRIB_FORMAT_32_32_32_32_UINT 0x00000112

#define GX2_ATTRIB_FORMAT_8_SNORM 0x00000200
#define GX2_ATTRIB_FORMAT_16_SNORM 0x00000202
#define GX2_ATTRIB_FORMAT_8_8_SNORM 0x00000204
#define GX2_ATTRIB_FORMAT_16_16_SNORM 0x00000207
#define GX2_ATTRIB_FORMAT_8_8_8_8_SNORM 0x0000020A
#define GX2_ATTRIB_FORMAT_10_10_10_2_SNORM 0x0000020B
#define GX2_ATTRIB_FORMAT_16_16_16_16_SNORM 0x0000020E

#define GX2_ATTRIB_FORMAT_8_SINT 0x00000300
#define GX2_ATTRIB_FORMAT_16_SINT 0x00000303
#define GX2_ATTRIB_FORMAT_8_8_SINT 0x00000304
#define GX2_ATTRIB_FORMAT_32_SINT 0x00000305
#define GX2_ATTRIB_FORMAT_16_16_SINT 0x00000307
#define GX2_ATTRIB_FORMAT_8_8_8_8_SINT 0x0000030A
#define GX2_ATTRIB_FORMAT_10_10_10_2_SINT 0x0000030B
#define GX2_ATTRIB_FORMAT_32_32_SINT 0x0000030C
#define GX2_ATTRIB_FORMAT_16_16_16_16_SINT 0x0000030E
#define GX2_ATTRIB_FORMAT_32_32_32_SINT 0x00000310
#define GX2_ATTRIB_FORMAT_32_32_32_32_SINT 0x00000312

#define GX2_ATTRIB_FORMAT_8_UINT_TO_FLOAT 0x00000800
#define GX2_ATTRIB_FORMAT_16_UINT_TO_FLOAT 0x00000802
#define GX2_ATTRIB_FORMAT_16_FLOAT 0x00000803
#define GX2_ATTRIB_FORMAT_8_8_UINT_TO_FLOAT 0x00000804
#define GX2_ATTRIB_FORMAT_32_FLOAT 0x00000806
#define GX2_ATTRIB_FORMAT_16_16_UINT_TO_FLOAT 0x00000807
#define GX2_ATTRIB_FORMAT_16_16_FLOAT 0x00000808
#define GX2_ATTRIB_FORMAT_10_11_11_FLOAT 0x00000809
#define GX2_ATTRIB_FORMAT_8_8_8_8_UINT_TO_FLOAT 0x0000080A
#define GX2_ATTRIB_FORMAT_32_32_FLOAT 0x0000080D
#define GX2_ATTRIB_FORMAT_16_16_16_16_UINT_TO_FLOAT 0x0000080E
#define GX2_ATTRIB_FORMAT_16_16_16_16_FLOAT 0x0000080F
#define GX2_ATTRIB_FORMAT_32_32_32_FLOAT 0x00000811
#define GX2_ATTRIB_FORMAT_32_32_32_32_FLOAT 0x00000813

#define GX2_ATTRIB_FORMAT_8_SINT_TO_FLOAT 0x00000A00
#define GX2_ATTRIB_FORMAT_16_SINT_TO_FLOAT 0x00000A02
#define GX2_ATTRIB_FORMAT_8_8_SINT_TO_FLOAT 0x00000A04
#define GX2_ATTRIB_FORMAT_16_16_SINT_TO_FLOAT 0x00000A07
#define GX2_ATTRIB_FORMAT_8_8_8_8_SINT_TO_FLOAT 0x00000A0A
#define GX2_ATTRIB_FORMAT_16_16_16_16_SINT_TO_FLOAT 0x00000A0E

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 attribute index types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_ATTRIB_INDEX_PER_VERTEX 0
#define GX2_ATTRIB_INDEX_PER_INSTANCE 1

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 shader modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SHADER_MODE_UNIFORM_REGISTER 0
#define GX2_SHADER_MODE_UNIFORM_BLOCK 1
#define GX2_SHADER_MODE_GEOMETRY_SHADER 2
#define GX2_SHADER_MODE_COMPUTE_SHADER 3

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 shader modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_COMP_SEL_NONE 0x04040405
#define GX2_COMP_SEL_X001 0x00040405
#define GX2_COMP_SEL_XY01 0x00010405
#define GX2_COMP_SEL_XYZ1 0x00010205
#define GX2_COMP_SEL_XYZW 0x00010203
#define GX2_COMP_SEL_XXXX 0x00000000
#define GX2_COMP_SEL_YYYY 0x01010101
#define GX2_COMP_SEL_ZZZZ 0x02020202
#define GX2_COMP_SEL_WWWW 0x03030303
#define GX2_COMP_SEL_WZYX 0x03020100
#define GX2_COMP_SEL_WXYZ 0x03000102

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 variable types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_VAR_TYPE_VOID 0
#define GX2_VAR_TYPE_BOOL 1
#define GX2_VAR_TYPE_INT 2
#define GX2_VAR_TYPE_UINT 3
#define GX2_VAR_TYPE_FLOAT 4
#define GX2_VAR_TYPE_DOUBLE 5
#define GX2_VAR_TYPE_VEC2 9
#define GX2_VAR_TYPE_VEC3 10
#define GX2_VAR_TYPE_VEC4 11
#define GX2_VAR_TYPE_MAT2 21
#define GX2_VAR_TYPE_MAT3 25
#define GX2_VAR_TYPE_MAT4 29

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 sample types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SAMPLER_TYPE_2D 1

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 index formats
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_INDEX_FORMAT_U16 4
#define GX2_INDEX_FORMAT_U32 9

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 primitive types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_PRIMITIVE_POINTS 0x01
#define GX2_PRIMITIVE_LINES 0x02
#define GX2_PRIMITIVE_LINE_STRIP 0x03
#define GX2_PRIMITIVE_TRIANGLES 0x04
#define GX2_PRIMITIVE_TRIANGLE_FAN 0x05
#define GX2_PRIMITIVE_TRIANGLE_STRIP 0x06
#define GX2_PRIMITIVE_RECTS 0x11
#define GX2_PRIMITIVE_LINE_LOOP 0x12
#define GX2_PRIMITIVE_QUADS 0x13
#define GX2_PRIMITIVE_QUAD_STRIP 0x14

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 clear modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_CLEAR_DEPTH 0x01
#define GX2_CLEAR_STENCIL 0x02
#define GX2_CLEAR_BOTH (GX2_CLEAR_DEPTH | GX2_CLEAR_STENCIL)

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 surface formats
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SURFACE_FORMAT_TC_R8_UNORM 0x00000001
#define GX2_SURFACE_FORMAT_T_R4_G4_UNORM 0x00000002
#define GX2_SURFACE_FORMAT_TCD_R16_UNORM 0x00000005
#define GX2_SURFACE_FORMAT_TC_R8_G8_UNORM 0x00000007
#define GX2_SURFACE_FORMAT_TCS_R5_G6_B5_UNORM 0x00000008
#define GX2_SURFACE_FORMAT_TC_R5_G5_B5_A1_UNORM 0x0000000A
#define GX2_SURFACE_FORMAT_TC_R4_G4_B4_A4_UNORM 0x0000000B
#define GX2_SURFACE_FORMAT_TC_A1_B5_G5_R5_UNORM 0x0000000C
#define GX2_SURFACE_FORMAT_TC_R16_G16_UNORM 0x0000000F
#define GX2_SURFACE_FORMAT_D_D24_S8_UNORM 0x00000011
#define GX2_SURFACE_FORMAT_T_R24_UNORM_X8 0x00000011
#define GX2_SURFACE_FORMAT_TCS_R10_G10_B10_A2_UNORM 0x00000019
#define GX2_SURFACE_FORMAT_TCS_R8_G8_B8_A8_UNORM 0x0000001A
#define GX2_SURFACE_FORMAT_TCS_A2_B10_G10_R10_UNORM 0x0000001B
#define GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_UNORM 0x0000001F
#define GX2_SURFACE_FORMAT_T_BC1_UNORM 0x00000031
#define GX2_SURFACE_FORMAT_T_BC2_UNORM 0x00000032
#define GX2_SURFACE_FORMAT_T_BC3_UNORM 0x00000033
#define GX2_SURFACE_FORMAT_T_BC4_UNORM 0x00000034
#define GX2_SURFACE_FORMAT_T_BC5_UNORM 0x00000035
#define GX2_SURFACE_FORMAT_T_NV12_UNORM 0x00000081

#define GX2_SURFACE_FORMAT_TC_R8_UINT 0x00000101
#define GX2_SURFACE_FORMAT_TC_R16_UINT 0x00000105
#define GX2_SURFACE_FORMAT_TC_R8_G8_UINT 0x00000107
#define GX2_SURFACE_FORMAT_TC_R32_UINT 0x0000010D
#define GX2_SURFACE_FORMAT_TC_R16_G16_UINT 0x0000010F
#define GX2_SURFACE_FORMAT_T_X24_G8_UINT 0x00000111
#define GX2_SURFACE_FORMAT_TC_R10_G10_B10_A2_UINT 0x00000119
#define GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_UINT 0x0000011A
#define GX2_SURFACE_FORMAT_TC_A2_B10_G10_R10_UINT 0x0000011B
#define GX2_SURFACE_FORMAT_T_X32_G8_UINT_X24 0x0000011C
#define GX2_SURFACE_FORMAT_TC_R32_G32_UINT 0x0000011D
#define GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_UINT 0x0000011F
#define GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_UINT 0x00000122

#define GX2_SURFACE_FORMAT_TC_R8_SNORM 0x00000201
#define GX2_SURFACE_FORMAT_TC_R16_SNORM 0x00000205
#define GX2_SURFACE_FORMAT_TC_R8_G8_SNORM 0x00000207
#define GX2_SURFACE_FORMAT_TC_R16_G16_SNORM 0x0000020F
#define GX2_SURFACE_FORMAT_T_R10_G10_B10_A2_SNORM 0x00000219
#define GX2_SURFACE_FORMAT_TC_R10_G10_B10_A2_SNORM 0x00000219
#define GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_SNORM 0x0000021A
#define GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_SNORM 0x0000021F
#define GX2_SURFACE_FORMAT_T_BC4_SNORM 0x00000234
#define GX2_SURFACE_FORMAT_T_BC5_SNORM 0x00000235

#define GX2_SURFACE_FORMAT_TC_R8_SINT 0x00000301
#define GX2_SURFACE_FORMAT_TC_R16_SINT 0x00000305
#define GX2_SURFACE_FORMAT_TC_R8_G8_SINT 0x00000307
#define GX2_SURFACE_FORMAT_TC_R32_SINT 0x0000030D
#define GX2_SURFACE_FORMAT_TC_R16_G16_SINT 0x0000030F
#define GX2_SURFACE_FORMAT_TC_R10_G10_B10_A2_SINT 0x00000319
#define GX2_SURFACE_FORMAT_TC_R8_G8_B8_A8_SINT 0x0000031A
#define GX2_SURFACE_FORMAT_TC_R32_G32_SINT 0x0000031D
#define GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_SINT 0x0000031F
#define GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_SINT 0x00000322

#define GX2_SURFACE_FORMAT_TCS_R8_G8_B8_A8_SRGB 0x0000041A
#define GX2_SURFACE_FORMAT_T_BC1_SRGB 0x00000431
#define GX2_SURFACE_FORMAT_T_BC2_SRGB 0x00000432
#define GX2_SURFACE_FORMAT_T_BC3_SRGB 0x00000433

#define GX2_SURFACE_FORMAT_TC_R16_FLOAT 0x00000806
#define GX2_SURFACE_FORMAT_TCD_R32_FLOAT 0x0000080E
#define GX2_SURFACE_FORMAT_TC_R16_G16_FLOAT 0x00000810
#define GX2_SURFACE_FORMAT_D_D24_S8_FLOAT 0x00000811
#define GX2_SURFACE_FORMAT_TC_R11_G11_B10_FLOAT 0x00000816
#define GX2_SURFACE_FORMAT_D_D32_FLOAT_S8_UINT_X24 0x0000081C
#define GX2_SURFACE_FORMAT_T_R32_FLOAT_X8_X24 0x0000081C
#define GX2_SURFACE_FORMAT_TC_R32_G32_FLOAT 0x0000081E
#define GX2_SURFACE_FORMAT_TC_R16_G16_B16_A16_FLOAT 0x00000820
#define GX2_SURFACE_FORMAT_TC_R32_G32_B32_A32_FLOAT 0x00000823

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 tile modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TILE_MODE_DEFAULT 0x00000000
#define GX2_TILE_MODE_LINEAR_ALIGNED 0x00000001
#define GX2_TILE_MODE_2D_THIN1 0x00000004

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 surface use
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SURFACE_USE_TEXTURE 0x00000001
#define GX2_SURFACE_USE_COLOR_BUFFER 0x00000002
#define GX2_SURFACE_USE_DEPTH_BUFFER 0x00000004
#define GX2_SURFACE_USE_SCAN_BUFFER 0x00000008
#define GX2_SURFACE_USE_FTV 0x80000000
#define GX2_SURFACE_USE_COLOR_BUFFER_TEXTURE (GX2_SURFACE_USE_COLOR_BUFFER | GX2_SURFACE_USE_TEXTURE)
#define GX2_SURFACE_USE_DEPTH_BUFFER_TEXTURE (GX2_SURFACE_USE_DEPTH_BUFFER | GX2_SURFACE_USE_TEXTURE)
#define GX2_SURFACE_USE_COLOR_BUFFER_FTV (GX2_SURFACE_USE_COLOR_BUFFER | GX2_SURFACE_USE_FTV)
#define GX2_SURFACE_USE_COLOR_BUFFER_TEXTURE_FTV (GX2_SURFACE_USE_COLOR_BUFFER_TEXTURE | GX2_SURFACE_USE_FTV)

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 surface dim
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SURFACE_DIM_1D 0x00000000
#define GX2_SURFACE_DIM_2D 0x00000001
#define GX2_SURFACE_DIM_3D 0x00000002
#define GX2_SURFACE_DIM_CUBE 0x00000003
#define GX2_SURFACE_DIM_1D_ARRAY 0x00000004
#define GX2_SURFACE_DIM_2D_ARRAY 0x00000005
#define GX2_SURFACE_DIM_2D_MSAA 0x00000006
#define GX2_SURFACE_DIM_2D_MSAA_ARRAY 0x00000007

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 AA modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_AA_MODE_1X 0x00000000
#define GX2_AA_MODE_2X 0x00000001
#define GX2_AA_MODE_4X 0x00000002
#define GX2_AA_MODE_8X 0x00000003

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 texture clamp
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TEX_CLAMP_WRAP 0x00000000
#define GX2_TEX_CLAMP_MIRROR 0x00000001
#define GX2_TEX_CLAMP_CLAMP 0x00000002
#define GX2_TEX_CLAMP_MIRROR_ONCE 0x00000003
#define GX2_TEX_CLAMP_CLAMP_HALF_BORDER 0x00000004
#define GX2_TEX_CLAMP_MIRROR_ONCE_HALF_BORDER 0x00000005
#define GX2_TEX_CLAMP_CLAMP_BORDER 0x00000006
#define GX2_TEX_CLAMP_MIRROR_ONCE_BORDER 0x00000007

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 texture filter
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TEX_XY_FILTER_POINT 0x00000000
#define GX2_TEX_XY_FILTER_BILINEAR 0x00000001

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 texture mip filter
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TEX_MIP_FILTER_NO_MIP 0x00000000
#define GX2_TEX_MIP_FILTER_POINT 0x00000001
#define GX2_TEX_MIP_FILTER_LINEAR 0x00000002

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 TV scan modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TV_SCAN_MODE_NONE 0x00000000
#define GX2_TV_SCAN_MODE_576I 0x00000001
#define GX2_TV_SCAN_MODE_480I 0x00000002
#define GX2_TV_SCAN_MODE_480P 0x00000003
#define GX2_TV_SCAN_MODE_720P 0x00000004
#define GX2_TV_SCAN_MODE_1080I 0x00000006
#define GX2_TV_SCAN_MODE_1080P 0x00000007

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 TV render modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TV_RENDER_480_NARROW 0x00000001
#define GX2_TV_RENDER_480_WIDE 0x00000002
#define GX2_TV_RENDER_720 0x00000003
#define GX2_TV_RENDER_1080 0x00000005

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 DRC render modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_DRC_NONE 0x00000000
#define GX2_DRC_SINGLE 0x00000001
#define GX2_DRC_DOUBLE 0x00000002
#define GX2_DRC_SINGLE_30HZ 0x00000004

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 buffering mode
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_BUFFERING_SINGLE 0x00000001
#define GX2_BUFFERING_DOUBLE 0x00000002
#define GX2_BUFFERING_TRIPLE 0x00000003
#define GX2_BUFFERING_QUAD
//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 scan targets
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_SCAN_TARGET_TV 0x00000001
#define GX2_SCAN_TARGET_DRC_FIRST 0x00000004
#define GX2_SCAN_TARGET_DRC_SECOND 0x00000008

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 invalidate types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_INVALIDATE_ATTRIB_BUFFER 0x00000001
#define GX2_INVALIDATE_TEXTURE 0x00000002
#define GX2_INVALIDATE_UNIFORM_BLOCK 0x00000004
#define GX2_INVALIDATE_SHADER 0x00000008
#define GX2_INVALIDATE_COLOR_BUFFER 0x00000010
#define GX2_INVALIDATE_DEPTH_BUFFER 0x00000020
#define GX2_INVALIDATE_CPU 0x00000040
#define GX2_INVALIDATE_CPU_ATTRIB_BUFFER (GX2_INVALIDATE_CPU | GX2_INVALIDATE_ATTRIB_BUFFER)
#define GX2_INVALIDATE_CPU_TEXTURE (GX2_INVALIDATE_CPU | GX2_INVALIDATE_TEXTURE)
#define GX2_INVALIDATE_CPU_UNIFORM_BLOCK (GX2_INVALIDATE_CPU | GX2_INVALIDATE_UNIFORM_BLOCK)
#define GX2_INVALIDATE_CPU_SHADER (GX2_INVALIDATE_CPU | GX2_INVALIDATE_SHADER)

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 swap modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_ENDIANSWAP_DEFAULT 0x00000003

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 tessellation modes
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_TESSELLATION_MODE_DISCRETE 0x00000000
#define GX2_TESSELLATION_MODE_CONTINUOUS 0x00000001
#define GX2_TESSELLATION_MODE_ADAPTIVE 0x00000002

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2 fetch shader types
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2_FETCH_SHADER_TESSELATION_NONE 0x00000000
#define GX2_FETCH_SHADER_TESSELATION_LINES 0x00000001
#define GX2_FETCH_SHADER_TESSELATION_TRIANGLES 0x00000002
#define GX2_FETCH_SHADER_TESSELATION_QUADS 0x00000003

//!-----------------------------------------------------------------------------------------------------------------------
//! GX2R resource flags
//!-----------------------------------------------------------------------------------------------------------------------
#define GX2R_RESOURCE_BIND_NONE 0
#define GX2R_RESOURCE_BIND_TEXTURE 1 << 0
#define GX2R_RESOURCE_BIND_COLOR_BUFFER 1 << 1
#define GX2R_RESOURCE_BIND_DEPTH_BUFFER 1 << 2
#define GX2R_RESOURCE_BIND_SCAN_BUFFER 1 << 3
#define GX2R_RESOURCE_BIND_VERTEX_BUFFER 1 << 4
#define GX2R_RESOURCE_BIND_INDEX_BUFFER 1 << 5
#define GX2R_RESOURCE_BIND_UNIFORM_BLOCK 1 << 6
#define GX2R_RESOURCE_BIND_SHADER_PROGRAM 1 << 7
#define GX2R_RESOURCE_BIND_STREAM_OUTPUT 1 << 8
#define GX2R_RESOURCE_BIND_DISPLAY_LIST 1 << 9
#define GX2R_RESOURCE_BIND_GS_RING_BUFFER 1 << 10
#define GX2R_RESOURCE_USAGE_CPU_READ 1 << 11
#define GX2R_RESOURCE_USAGE_CPU_WRITE 1 << 12
#define GX2R_RESOURCE_USAGE_GPU_READ 1 << 13
#define GX2R_RESOURCE_USAGE_GPU_WRITE 1 << 14
#define GX2R_RESOURCE_USAGE_DMA_READ 1 << 15
#define GX2R_RESOURCE_USAGE_DMA_WRITE 1 << 16
#define GX2R_RESOURCE_USAGE_FORCE_MEM1 1 << 17
#define GX2R_RESOURCE_USAGE_FORCE_MEM2 1 << 18
#define GX2R_RESOURCE_DISABLE_CPU_INVALIDATE 1 << 20
#define GX2R_RESOURCE_DISABLE_GPU_INVALIDATE 1 << 21
#define GX2R_RESOURCE_LOCKED_READ_ONLY 1 << 22
#define GX2R_RESOURCE_GX2R_ALLOCATED 1 << 29
#define GX2R_RESOURCE_LOCKED 1 << 30

typedef enum GX2BlendMode {
    GX2_BLEND_MODE_ZERO = 0,
    GX2_BLEND_MODE_ONE = 1,
    GX2_BLEND_MODE_SRC_COLOR = 2,
    GX2_BLEND_MODE_INV_SRC_COLOR = 3,
    GX2_BLEND_MODE_SRC_ALPHA = 4,
    GX2_BLEND_MODE_INV_SRC_ALPHA = 5,
    GX2_BLEND_MODE_DST_ALPHA = 6,
    GX2_BLEND_MODE_INV_DST_ALPHA = 7,
    GX2_BLEND_MODE_DST_COLOR = 8,
    GX2_BLEND_MODE_INV_DST_COLOR = 9,
    GX2_BLEND_MODE_SRC_ALPHA_SAT = 10,
    GX2_BLEND_MODE_BOTH_SRC_ALPHA = 11,
    GX2_BLEND_MODE_BOTH_INV_SRC_ALPHA = 12,
    GX2_BLEND_MODE_BLEND_FACTOR = 13,
    GX2_BLEND_MODE_INV_BLEND_FACTOR = 14,
    GX2_BLEND_MODE_SRC1_COLOR = 15,
    GX2_BLEND_MODE_INV_SRC1_COLOR = 16,
    GX2_BLEND_MODE_SRC1_ALPHA = 17,
    GX2_BLEND_MODE_INV_SRC1_ALPHA = 18,
} GX2BlendMode;

typedef enum GX2BlendCombineMode {
    GX2_BLEND_COMBINE_MODE_ADD = 0,
    GX2_BLEND_COMBINE_MODE_SUB = 1,
    GX2_BLEND_COMBINE_MODE_MIN = 2,
    GX2_BLEND_COMBINE_MODE_MAX = 3,
    GX2_BLEND_COMBINE_MODE_REV_SUB = 4,
} GX2BlendCombineMode;

typedef enum GX2CompareFunction {
    GX2_COMPARE_FUNC_NEVER = 0,
    GX2_COMPARE_FUNC_LESS = 1,
    GX2_COMPARE_FUNC_EQUAL = 2,
    GX2_COMPARE_FUNC_LEQUAL = 3,
    GX2_COMPARE_FUNC_GREATER = 4,
    GX2_COMPARE_FUNC_NOT_EQUAL = 5,
    GX2_COMPARE_FUNC_GEQUAL = 6,
    GX2_COMPARE_FUNC_ALWAYS = 7,
} GX2CompareFunction;

typedef enum GX2InvalidateMode {
    GX2_INVALIDATE_MODE_NONE = 0,
    GX2_INVALIDATE_MODE_ATTRIBUTE_BUFFER = 1 << 0,
    GX2_INVALIDATE_MODE_TEXTURE = 1 << 1,
    GX2_INVALIDATE_MODE_UNIFORM_BLOCK = 1 << 2,
    GX2_INVALIDATE_MODE_SHADER = 1 << 3,
    GX2_INVALIDATE_MODE_COLOR_BUFFER = 1 << 4,
    GX2_INVALIDATE_MODE_DEPTH_BUFFER = 1 << 5,
    GX2_INVALIDATE_MODE_CPU = 1 << 6,
    GX2_INVALIDATE_MODE_STREAM_OUT_BUFFER = 1 << 7,
    GX2_INVALIDATE_MODE_EXPORT_BUFFER = 1 << 8,
    GX2_INVALIDATE_MODE_CPU_ATTRIBUTE_BUFFER = GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_ATTRIBUTE_BUFFER,
    GX2_INVALIDATE_MODE_CPU_TEXTURE = GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_TEXTURE,
    GX2_INVALIDATE_MODE_CPU_SHADER = GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_SHADER,
} GX2InvalidateMode;

typedef enum GX2PrimitiveMode {
    GX2_PRIMITIVE_MODE_POINTS = 1,
    GX2_PRIMITIVE_MODE_LINES = 2,
    GX2_PRIMITIVE_MODE_LINE_STRIP = 3,
    GX2_PRIMITIVE_MODE_TRIANGLES = 4,
    GX2_PRIMITIVE_MODE_TRIANGLE_FAN = 5,
    GX2_PRIMITIVE_MODE_TRIANGLE_STRIP = 6,
    GX2_PRIMITIVE_MODE_LINES_ADJACENCY = 10,
    GX2_PRIMITIVE_MODE_LINE_STRIP_ADJACENCY = 11,
    GX2_PRIMITIVE_MODE_TRIANGLES_ADJACENCY = 12,
    GX2_PRIMITIVE_MODE_TRIANGLE_STRIP_ADJACENCY = 13,
    GX2_PRIMITIVE_MODE_RECTS = 17,
    GX2_PRIMITIVE_MODE_LINE_LOOP = 18,
    GX2_PRIMITIVE_MODE_QUADS = 19,
    GX2_PRIMITIVE_MODE_QUAD_STRIP = 20,
} GX2PrimitiveMode;

typedef enum GX2IndexType {
    GX2_INDEX_TYPE_U16_LE = 0,
    GX2_INDEX_TYPE_U32_LE = 1,
    GX2_INDEX_TYPE_U16 = 4,
    GX2_INDEX_TYPE_U32 = 9,
} GX2IndexType;

typedef enum GX2SurfaceDim {
    GX2_SURFACE_DIM_TEXTURE_1D = 0,
    GX2_SURFACE_DIM_TEXTURE_2D = 1,
    GX2_SURFACE_DIM_TEXTURE_3D = 2,
    GX2_SURFACE_DIM_TEXTURE_CUBE = 3,
    GX2_SURFACE_DIM_TEXTURE_1D_ARRAY = 4,
    GX2_SURFACE_DIM_TEXTURE_2D_ARRAY = 5,
    GX2_SURFACE_DIM_TEXTURE_2D_MSAA = 6,
    GX2_SURFACE_DIM_TEXTURE_2D_MSAA_ARRAY = 7,
} GX2SurfaceDim;

typedef enum GX2SurfaceFormat {
    GX2_SURFACE_FORMAT_INVALID = 0x00,
    GX2_SURFACE_FORMAT_UNORM_R4_G4 = 0x02,
    GX2_SURFACE_FORMAT_UNORM_R4_G4_B4_A4 = 0x0b,
    GX2_SURFACE_FORMAT_UNORM_R8 = 0x01,
    GX2_SURFACE_FORMAT_UNORM_R8_G8 = 0x07,
    GX2_SURFACE_FORMAT_UNORM_R8_G8_B8_A8 = 0x01a,
    GX2_SURFACE_FORMAT_UNORM_R16 = 0x05,
    GX2_SURFACE_FORMAT_UNORM_R16_G16 = 0x0f,
    GX2_SURFACE_FORMAT_UNORM_R16_G16_B16_A16 = 0x01f,
    GX2_SURFACE_FORMAT_UNORM_R5_G6_B5 = 0x08,
    GX2_SURFACE_FORMAT_UNORM_R5_G5_B5_A1 = 0x0a,
    GX2_SURFACE_FORMAT_UNORM_A1_B5_G5_R5 = 0x0c,
    GX2_SURFACE_FORMAT_UNORM_R24_X8 = 0x011,
    GX2_SURFACE_FORMAT_UNORM_A2_B10_G10_R10 = 0x01b,
    GX2_SURFACE_FORMAT_UNORM_R10_G10_B10_A2 = 0x019,
    GX2_SURFACE_FORMAT_UNORM_BC1 = 0x031,
    GX2_SURFACE_FORMAT_UNORM_BC2 = 0x032,
    GX2_SURFACE_FORMAT_UNORM_BC3 = 0x033,
    GX2_SURFACE_FORMAT_UNORM_BC4 = 0x034,
    GX2_SURFACE_FORMAT_UNORM_BC5 = 0x035,
    GX2_SURFACE_FORMAT_UNORM_NV12 = 0x081,

    GX2_SURFACE_FORMAT_UINT_R8 = 0x101,
    GX2_SURFACE_FORMAT_UINT_R8_G8 = 0x107,
    GX2_SURFACE_FORMAT_UINT_R8_G8_B8_A8 = 0x11a,
    GX2_SURFACE_FORMAT_UINT_R16 = 0x105,
    GX2_SURFACE_FORMAT_UINT_R16_G16 = 0x10f,
    GX2_SURFACE_FORMAT_UINT_R16_G16_B16_A16 = 0x11f,
    GX2_SURFACE_FORMAT_UINT_R32 = 0x10d,
    GX2_SURFACE_FORMAT_UINT_R32_G32 = 0x11d,
    GX2_SURFACE_FORMAT_UINT_R32_G32_B32_A32 = 0x122,
    GX2_SURFACE_FORMAT_UINT_A2_B10_G10_R10 = 0x11b,
    GX2_SURFACE_FORMAT_UINT_R10_G10_B10_A2 = 0x119,
    GX2_SURFACE_FORMAT_UINT_X24_G8 = 0x111,
    GX2_SURFACE_FORMAT_UINT_G8_X24 = 0x11c,

    GX2_SURFACE_FORMAT_SNORM_R8 = 0x201,
    GX2_SURFACE_FORMAT_SNORM_R8_G8 = 0x207,
    GX2_SURFACE_FORMAT_SNORM_R8_G8_B8_A8 = 0x21a,
    GX2_SURFACE_FORMAT_SNORM_R16 = 0x205,
    GX2_SURFACE_FORMAT_SNORM_R16_G16 = 0x20f,
    GX2_SURFACE_FORMAT_SNORM_R16_G16_B16_A16 = 0x21f,
    GX2_SURFACE_FORMAT_SNORM_R10_G10_B10_A2 = 0x219,
    GX2_SURFACE_FORMAT_SNORM_BC4 = 0x234,
    GX2_SURFACE_FORMAT_SNORM_BC5 = 0x235,

    GX2_SURFACE_FORMAT_SINT_R8 = 0x301,
    GX2_SURFACE_FORMAT_SINT_R8_G8 = 0x307,
    GX2_SURFACE_FORMAT_SINT_R8_G8_B8_A8 = 0x31a,
    GX2_SURFACE_FORMAT_SINT_R16 = 0x305,
    GX2_SURFACE_FORMAT_SINT_R16_G16 = 0x30f,
    GX2_SURFACE_FORMAT_SINT_R16_G16_B16_A16 = 0x31f,
    GX2_SURFACE_FORMAT_SINT_R32 = 0x30d,
    GX2_SURFACE_FORMAT_SINT_R32_G32 = 0x31d,
    GX2_SURFACE_FORMAT_SINT_R32_G32_B32_A32 = 0x322,
    GX2_SURFACE_FORMAT_SINT_R10_G10_B10_A2 = 0x319,

    GX2_SURFACE_FORMAT_SRGB_R8_G8_B8_A8 = 0x41a,
    GX2_SURFACE_FORMAT_SRGB_BC1 = 0x431,
    GX2_SURFACE_FORMAT_SRGB_BC2 = 0x432,
    GX2_SURFACE_FORMAT_SRGB_BC3 = 0x433,

    GX2_SURFACE_FORMAT_FLOAT_R32 = 0x80e,
    GX2_SURFACE_FORMAT_FLOAT_R32_G32 = 0x81e,
    GX2_SURFACE_FORMAT_FLOAT_R32_G32_B32_A32 = 0x823,
    GX2_SURFACE_FORMAT_FLOAT_R16 = 0x806,
    GX2_SURFACE_FORMAT_FLOAT_R16_G16 = 0x810,
    GX2_SURFACE_FORMAT_FLOAT_R16_G16_B16_A16 = 0x820,
    GX2_SURFACE_FORMAT_FLOAT_R11_G11_B10 = 0x816,
    GX2_SURFACE_FORMAT_FLOAT_D24_S8 = 0x811,
    GX2_SURFACE_FORMAT_FLOAT_X8_X24 = 0x81c,
} GX2SurfaceFormat;

typedef enum GX2AAMode {
    GX2_AA_MODE1X = 0,
    GX2_AA_MODE2X = 1,
    GX2_AA_MODE4X = 2
} GX2AAMode;

typedef enum GX2_SQ_SEL {
    GX2_SQ_SEL_X = 0,
    GX2_SQ_SEL_Y = 1,
    GX2_SQ_SEL_Z = 2,
    GX2_SQ_SEL_W = 3,

    GX2_SQ_SEL_R = 0,
    GX2_SQ_SEL_G = 1,
    GX2_SQ_SEL_B = 2,
    GX2_SQ_SEL_A = 3,

    GX2_SQ_SEL_0 = 4,
    GX2_SQ_SEL_1 = 5,
    GX2_SQ_SEL_MASK = 7,
} GX2_SQ_SEL;

#define GX2_SEL_MASK(x, y, z, w) (((x) << 24) | ((y) << 16) | ((z) << 8) | (w))
#define GX2_COMP_MAP(x, y, z, w) (((x) << 24) | ((y) << 16) | ((z) << 8) | (w))

typedef enum GX2AttribFormat {
    GX2_ATTRIB_TYPE_8 = 0x00,
    GX2_ATTRIB_TYPE_4_4 = 0x01,
    GX2_ATTRIB_TYPE_16 = 0x02,
    GX2_ATTRIB_TYPE_16_FLOAT = 0x03,
    GX2_ATTRIB_TYPE_8_8 = 0x04,
    GX2_ATTRIB_TYPE_32 = 0x05,
    GX2_ATTRIB_TYPE_32_FLOAT = 0x06,
    GX2_ATTRIB_TYPE_16_16 = 0x07,
    GX2_ATTRIB_TYPE_16_16_FLOAT = 0x08,
    GX2_ATTRIB_TYPE_10_11_11_FLOAT = 0x09,
    GX2_ATTRIB_TYPE_8_8_8_8 = 0x0A,
    GX2_ATTRIB_TYPE_10_10_10_2 = 0x0B,
    GX2_ATTRIB_TYPE_32_32 = 0x0C,
    GX2_ATTRIB_TYPE_32_32_FLOAT = 0x0D,
    GX2_ATTRIB_TYPE_16_16_16_16 = 0x0E,
    GX2_ATTRIB_TYPE_16_16_16_16_FLOAT = 0x0F,
    GX2_ATTRIB_TYPE_32_32_32 = 0x10,
    GX2_ATTRIB_TYPE_32_32_32_FLOAT = 0x11,
    GX2_ATTRIB_TYPE_32_32_32_32 = 0x12,
    GX2_ATTRIB_TYPE_32_32_32_32_FLOAT = 0x13,

    GX2_ATTRIB_FLAG_INTEGER = 0x100,
    GX2_ATTRIB_FLAG_SIGNED = 0x200,
    GX2_ATTRIB_FLAG_DEGAMMA = 0x400,
    GX2_ATTRIB_FLAG_SCALED = 0x800,

    GX2_ATTRIB_FORMAT_UNORM_8 = GX2_ATTRIB_TYPE_8,
    GX2_ATTRIB_FORMAT_UNORM_8_8 = GX2_ATTRIB_TYPE_8_8,
    GX2_ATTRIB_FORMAT_UNORM_8_8_8_8 = GX2_ATTRIB_TYPE_8_8_8_8,

    GX2_ATTRIB_FORMAT_UINT_8 = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8,
    GX2_ATTRIB_FORMAT_UINT_8_8 = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8,
    GX2_ATTRIB_FORMAT_UINT_8_8_8_8 = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8_8_8,

    GX2_ATTRIB_FORMAT_SNORM_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8,
    GX2_ATTRIB_FORMAT_SNORM_8_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8_8,
    GX2_ATTRIB_FORMAT_SNORM_8_8_8_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8_8_8_8,

    GX2_ATTRIB_FORMAT_SINT_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8,
    GX2_ATTRIB_FORMAT_SINT_8_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8,
    GX2_ATTRIB_FORMAT_SINT_8_8_8_8 = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8_8_8,

    GX2_ATTRIB_FORMAT_FLOAT_32 = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_FLOAT,
    GX2_ATTRIB_FORMAT_FLOAT_32_32 = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_FLOAT,
    GX2_ATTRIB_FORMAT_FLOAT_32_32_32 = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_32_FLOAT,
    GX2_ATTRIB_FORMAT_FLOAT_32_32_32_32 = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_32_32_FLOAT,
} GX2AttribFormat;

typedef enum GX2TexClampMode {
    GX2_TEX_CLAMP_MODE_WRAP = 0,
    GX2_TEX_CLAMP_MODE_MIRROR = 1,
    GX2_TEX_CLAMP_MODE_CLAMP = 2,
    GX2_TEX_CLAMP_MODE_MIRROR_ONCE = 3,
    GX2_TEX_CLAMP_MODE_CLAMP_BORDER = 6,
} GX2TexClampMode;

typedef enum GX2TexXYFilterMode {
    GX2_TEX_XY_FILTER_MODE_POINT = 0,
    GX2_TEX_XY_FILTER_MODE_LINEAR = 1,
} GX2TexXYFilterMode;

typedef enum GX2EndianSwapMode {
    GX2_ENDIAN_SWAP_NONE = 0,
    GX2_ENDIAN_SWAP_8_IN_16 = 1,
    GX2_ENDIAN_SWAP_8_IN_32 = 2,
    GX2_ENDIAN_SWAP_DEFAULT = 3,
} GX2EndianSwapMode;

typedef enum GX2FetchShaderType {
    GX2_FETCH_SHADER_TESSELLATION_NONE = 0,
    GX2_FETCH_SHADER_TESSELLATION_LINE = 1,
    GX2_FETCH_SHADER_TESSELLATION_TRIANGLE = 2,
    GX2_FETCH_SHADER_TESSELLATION_QUAD = 3,
} GX2FetchShaderType;

typedef struct _GX2RBuffer {
    u32 flags;
    u32 elemSize;
    u32 elemCount;
    void* buffer;
} GX2RBuffer;

typedef struct _GX2ContextState {
    u8 data[GX2_CONTEXT_STATE_SIZE];
} GX2ContextState;

typedef struct _GX2Surface {
    s32 dimension;
    u32 width;
    u32 height;
    u32 depth;
    u32 numMips;
    s32 format;
    s32 aa;
    s32 use;
    u32 imageSize;
    void* imageData;
    u32 mipSize;
    void* mipData;
    s32 tile;
    u32 swizzle;
    u32 align;
    u32 pitch;
    u32 mipOffset[13];
} GX2Surface;

typedef struct _GX2ColorBuffer {
    GX2Surface surface;
    u32 viewMip;
    u32 viewFirstSlice;
    u32 viewSlicesCount;
    void* auxData;
    u32 auxSize;
    u32 regs[5];
} GX2ColorBuffer;

typedef struct _GX2DepthBuffer {
    GX2Surface surface;
    u32 viewMip;
    u32 viewFirstSlice;
    u32 viewSlicesCount;
    void* hiZ_data;
    u32 hiZ_size;
    f32 clearDepth;
    u32 clearStencil;
    u32 regs[7];
} GX2DepthBuffer;

typedef struct _GX2Texture {
    GX2Surface surface;
    u32 viewFirstMip;
    u32 viewMipsCount;
    u32 viewFirstSlice;
    u32 viewSlicesCount;
    u32 componentSelector;
    u32 regs[5];
} GX2Texture;

typedef struct _GX2Sampler {
    u32 regs[3];
} GX2Sampler;

typedef struct _GX2AttribStream {
    u32 location;
    u32 buffer;
    u32 offset;
    s32 format;
    s32 indexType;
    u32 divisor;
    u32 destinationSelector;
    s32 endianSwap;
} GX2AttribStream;

typedef struct _GX2FetchShader {
    s32 type;
    u32 reg;
    u32 shaderSize;
    void* shaderProgram;
    u32 attributesCount;
    u32 divisor[3];
} GX2FetchShader;

typedef struct _GX2AttribVar {
    const char* name;
    s32 varType;
    u32 arrayCount;
    u32 location;
} GX2AttribVar;

typedef struct _GX2UniformBlock {
    const char* name;
    u32 location;
    u32 blockSize;
} GX2UniformBlock;

typedef struct _GX2UniformInitialValue {
    f32 value[4];
    u32 offset;
} GX2UniformInitialValue;

typedef struct _GX2SamplerVar {
    const char* name;
    s32 samplerType;
    u32 location;
} GX2SamplerVar;

typedef struct _GX2UniformVar {
    const char* name;
    s32 varType;
    u32 arrayCount;
    u32 offset;
    u32 blockIndex;
} GX2UniformVar;

typedef struct _GX2VertexShader {
    u32 regs[52];
    u32 shaderSize;
    void* shaderData;
    s32 shaderMode;
    u32 uniformBlocksCount;
    GX2UniformBlock* uniformBlock;
    u32 uniformVarsCount;
    GX2UniformVar* uniformVar;
    u32 initialValuesCount;
    GX2UniformInitialValue* initialValue;
    u32 loopsCount;
    void* loopsData;
    u32 samplerVarsCount;
    GX2SamplerVar* samplerVar;
    u32 attributeVarsCount;
    GX2AttribVar* attributeVar;
    u32 data[6];
    GX2RBuffer shaderProgramBuffer;
} GX2VertexShader;

typedef struct _GX2PixelShader {
    u32 regs[41];
    u32 shaderSize;
    void* shaderData;
    s32 shaderMode;
    u32 uniformBlocksCount;
    GX2UniformBlock* uniformBlock;
    u32 uniformVarsCount;
    GX2UniformVar* uniformVar;
    u32 initialValuesCount;
    GX2UniformInitialValue* initialValue;
    u32 loopsCount;
    void* loopsData;
    u32 samplerVarsCount;
    GX2SamplerVar* samplerVar;
    GX2RBuffer shaderProgramBuffer;
} GX2PixelShader;

typedef struct _GX2GeometryShader {
    u32 regs[19];
    u32 shaderSize;
    void* shaderData;
    u32 vertexShaderSize;
    void* vertexShaderData;
    s32 shaderMode;
    u32 uniformBlocksCount;
    GX2UniformBlock* uniformBlock;
    u32 uniformVarsCount;
    GX2UniformVar* uniformVar;
    u32 initialValuesCount;
    GX2UniformInitialValue* initialValue;
    u32 loopsCount;
    void* loopsData;
    u32 samplerVarsCount;
    GX2SamplerVar* samplerVar;
    u32 data[6];
    GX2RBuffer shaderProgramBuffer;
    GX2RBuffer vertexShaderProgramBuffer;
} GX2GeometryShader;

static const u32 attributeDestCompSelector[20] = {
    GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_X001, GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_X001,
    GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW,
    GX2_COMP_SEL_XY01, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZ1,
    GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW
};

static const u32 textureCompSelector[54] = {
    GX2_COMP_SEL_NONE, GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_X001,
    GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW,
    GX2_COMP_SEL_WZYX, GX2_COMP_SEL_X001, GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XY01, GX2_COMP_SEL_NONE,
    GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_NONE,
    GX2_COMP_SEL_NONE, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_WZYX, GX2_COMP_SEL_XY01, GX2_COMP_SEL_XY01,
    GX2_COMP_SEL_XY01, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_NONE, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW,
    GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_X001,
    GX2_COMP_SEL_XY01, GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_NONE, GX2_COMP_SEL_XYZ1,
    GX2_COMP_SEL_XYZ1, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_XYZW, GX2_COMP_SEL_X001, GX2_COMP_SEL_XY01
};

typedef struct _GX2Color {
    u8 r, g, b, a;
} GX2Color;

typedef struct _GX2ColorF32 {
    f32 r, g, b, a;
} GX2ColorF32;

typedef void* (*GX2RAllocFunction)(u32, u32, u32);
typedef void (*GX2RFreeFunction)(u32, void*);

#ifdef __cplusplus
}
#endif
