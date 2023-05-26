#pragma once

#include "dynlibs/os/functions.h"
#include <alloca.h>
#include <cstdarg>
#include <stdio.h>
#include <string.h>

namespace pe {

#define PE_LOG_MSG(MSG) ::OSConsoleWrite(MSG, ::strlen(MSG));
#define PE_LOG_MSG_SIZE(MSG, SIZE) ::OSConsoleWrite(MSG, SIZE);

#define PE_LOG(FMT, ...)                                 \
    do {                                                 \
        int length = ::snprintf(0, 0, FMT, __VA_ARGS__); \
        char* data = (char*)::alloca(length + 1);        \
        ::snprintf(data, length + 1, FMT, __VA_ARGS__);  \
        PE_LOG_MSG_SIZE(data, length)                    \
    } while (0)

} // namespace pe
