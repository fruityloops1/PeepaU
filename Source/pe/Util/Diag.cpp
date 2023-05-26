#include "dynlibs/os/functions.h"
#include "pe/Util/Diag.h"
#include "pe/Util/Log.h"

namespace pe {

void abort()
{
    OSFatal("Abort");
}

void abortWithMsg(const char* fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    pe::log(fmt, arg);
    va_end(arg);
    abort();
}

} // namespace pe
