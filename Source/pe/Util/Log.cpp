#include "dynlibs/os/functions.h"
#include "pe/Util/Log.h"
#include <alloca.h>
#include <stdio.h>

namespace pe {

int log(const char* fmt, va_list arg)
{
    int length = vsnprintf(0, 0, fmt, arg);
    char* data = (char*)alloca(length + 1);
    vsnprintf(data, length + 1, fmt, arg);
    OSConsoleWrite(data, length);
    return length;
}

int log(const char* fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    int length = log(fmt, arg);
    va_end(arg);
    return length;
}

} // namespace pe
