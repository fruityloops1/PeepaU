#pragma once

#include <stdint.h>

bool GfxHeapInitMEM1();

bool GfxHeapDestroyMEM1();

bool GfxHeapInitForeground();

bool GfxHeapDestroyForeground();

void* GfxHeapAllocMEM1(uint32_t size,
    uint32_t alignment);

void GfxHeapFreeMEM1(void* block);

void* GfxHeapAllocForeground(uint32_t size,
    uint32_t alignment);

void GfxHeapFreeForeground(void* block);

void* GfxHeapAllocMEM2(uint32_t size,
    uint32_t alignment);

void GfxHeapFreeMEM2(void* block);
