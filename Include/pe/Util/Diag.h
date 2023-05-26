#pragma once

#include "pe/Util/Log.h"

namespace pe {

void abort();
void abortWithMsg(const char* fmt, ...);

#define PE_ASSERT(COND)                                                                 \
    do {                                                                                \
        if (!(COND)) {                                                                  \
            pe::abortWithMsg("Assertion failed: %s:%d: %s", __FILE__, __LINE__, #COND); \
        }                                                                               \
    } while (0)

} // namespace pe
