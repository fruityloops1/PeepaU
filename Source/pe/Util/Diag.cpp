#include "dynlibs/os/functions.h"
#include "pe/Util/Diag.h"
#include "pe/Util/Log.h"

namespace pe {

void abort()
{
    OSFatal("Abort");
    *(int*)0 = 0x123456;
    while (true)
        ;
}

void assertionFailure(const char* file, int line, const char* failedCondition)
{
    PE_ABORT_MSG("Assertion failed: %s:%d: %s", file, line, failedCondition);
}

} // namespace pe
