#pragma once

#include <cstdarg>

namespace pe {

int log(const char* fmt, va_list arg);
int log(const char* fmt, ...);

} // namespace pe
