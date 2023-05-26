#include "dynlibs/os/functions.h"
#include "pe/Util/DbgHeap.h"
#include "pe/Util/Log.h"
#include <ctype.h>
#include <string.h>

extern "C" int printf(const char* fmt, ...)
{
    return 0;
}

extern "C" void* memcpy(void* DST, const void* SRC, size_t LEN)
{
    return OSBlockMove(DST, SRC, LEN, 0);
}

extern "C" void* memset(void* DST, int value, size_t LEN)
{
    return OSBlockSet(DST, value, LEN);
}

extern "C" void* malloc(size_t size)
{
    return pe::getDbgHeap()->tryAlloc(size, 4);
}

extern "C" void free(void* ptr)
{
    return pe::getDbgHeap()->free(ptr);
}

void operator delete(void* ptr)
{
    free(ptr);
}

extern "C" void __gh_set_errno(int errno)
{
    *__gh_errno_ptr() = errno;
}

// https://github.com/GaloisInc/minlibc/blob/master/atof.c

extern "C" double atof(const char* s)
{
    double a = 0.0;
    int e = 0;
    int c;
    while ((c = *s++) != '\0' && isdigit(c)) {
        a = a * 10.0 + (c - '0');
    }
    if (c == '.') {
        while ((c = *s++) != '\0' && isdigit(c)) {
            a = a * 10.0 + (c - '0');
            e = e - 1;
        }
    }
    if (c == 'e' || c == 'E') {
        int sign = 1;
        int i = 0;
        c = *s++;
        if (c == '+')
            c = *s++;
        else if (c == '-') {
            c = *s++;
            sign = -1;
        }
        while (isdigit(c)) {
            i = i * 10 + (c - '0');
            c = *s++;
        }
        e += i * sign;
    }
    while (e > 0) {
        a *= 10.0;
        e--;
    }
    while (e < 0) {
        a *= 0.1;
        e++;
    }
    return a;
}