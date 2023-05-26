#pragma once

#include "pe/Util/Log.h"

namespace pe {

void abort();
void assertionFailure(const char* file, int line, const char* failedCondition);

#define PE_ABORT() ::pe::abort

#define PE_ABORT_MSG(MSG, ...) \
    PE_LOG(MSG, __VA_ARGS__);  \
    ::pe::abort()

#define PE_ASSERT(COND)                                      \
    do {                                                     \
        if (!(COND)) {                                       \
            pe::assertionFailure(__FILE__, __LINE__, #COND); \
        }                                                    \
    } while (0)

} // namespace pe
