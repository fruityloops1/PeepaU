#include "dynlibs/gx2/functions.h"
#include "dynlibs/os/functions.h"
#include "dynlibs/padscore/functions.h"
#include "dynlibs/vpad/functions.h"
#include "imgui_gx2/imgui_gx2.h"
#include "pe/Util/DbgHeap.h"
#include "pe/Util/Log.h"
#include <sead/basis/seadNew.h>
#include <sead/heap/seadHeapMgr.h>

extern "C" void (*_ctors[])();

OsSpecifics osSpecifics;
extern u32 BLOSDynLoad_Acquire;
extern u32 BOSDynLoad_FindExport;

uintptr_t extractAddrFromInstr(const u32* instr)
{
    uintptr_t ret = *instr & 0x03FFFFFCU;

    if (!(*instr & 2))
    {
        // sign extend offset
        if (ret & 0x02000000U)
            ret |= 0xFE000000U;

        // make relative
        ret += (uintptr_t)instr;
    }

    return ret;
}

extern "C" void initialize()
{
    for (int i = 0; _ctors[i]; i++)
        (*_ctors[i])();

    // Set OSDynLoad_Acquire and OSDynLoad_FindExport
    OS_SPECIFICS->addr_OSDynLoad_Acquire = extractAddrFromInstr(&BLOSDynLoad_Acquire);
    OS_SPECIFICS->addr_OSDynLoad_FindExport = extractAddrFromInstr(&BOSDynLoad_FindExport);

    InitOSFunctionPointers();
    InitGX2FunctionPointers();
    InitVPADFunctionPointers();
    InitPadscoreFunctionPointers();

    PE_LOG_MSG("Peepa");
}

extern "C" void initializeGameFramework()
{
    PE_LOG_MSG("Creating DbgHeap");
    pe::getDbgHeap() = sead::ExpHeap::tryCreate(4 * 1024 * 1024, "DbgHeap", sead::HeapMgr::getRootHeap(0), 4, sead::Heap::cHeapDirection_Forward, false);
    char* d = new (pe::getDbgHeap()) char;
    PE_LOG("Test alloc: %p", d);

    imgui_gx2::initialize();
}