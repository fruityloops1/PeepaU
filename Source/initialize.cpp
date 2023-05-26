#include "dynlibs/gx2/functions.h"
#include "dynlibs/os/functions.h"
#include "imgui/imgui.h"
#include "pe/Util/DbgHeap.h"
#include "pe/Util/Log.h"
#include <sead/basis/seadNew.h>
#include <sead/heap/seadHeapMgr.h>

extern "C" void (*_ctors[])();

OsSpecifics osSpecifics;
extern u32 BLOSDynLoad_Acquire;
extern u32 BOSDynLoad_FindExport;

extern "C" void initialize()
{
    for (int i = 0; _ctors[i]; i++)
        (*_ctors[i])();

    // Set OSDynLoad_Acquire and OSDynLoad_FindExport
    OS_SPECIFICS->addr_OSDynLoad_Acquire = (u32)(BLOSDynLoad_Acquire & 0x03FFFFFC);
    OS_SPECIFICS->addr_OSDynLoad_FindExport = (u32)(BOSDynLoad_FindExport & 0x03FFFFFC);

    if (!(BLOSDynLoad_Acquire & 2))
        OS_SPECIFICS->addr_OSDynLoad_Acquire += (u32)&BLOSDynLoad_Acquire;
    if (!(BOSDynLoad_FindExport & 2))
        OS_SPECIFICS->addr_OSDynLoad_FindExport += (u32)&BOSDynLoad_FindExport;

    InitOSFunctionPointers();
    InitGX2FunctionPointers();

    pe::log("Peepa");
}

extern "C" void initializeGameFramework()
{
    pe::log("Creating DbgHeap");
    pe::getDbgHeap() = sead::ExpHeap::tryCreate(1 * 1024 * 1024, "DbgHeap", sead::HeapMgr::getRootHeap(0), 4, sead::Heap::cHeapDirection_Forward, false);
    char* d = new (pe::getDbgHeap()) char;
    pe::log("Test alloc: %p", d);
}