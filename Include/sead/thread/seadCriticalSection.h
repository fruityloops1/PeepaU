#ifndef SEAD_CRITICAL_SECTION_H_
#define SEAD_CRITICAL_SECTION_H_

#include "dynlibs/os/types.h"
#include <sead/heap/seadDisposer.h>

namespace sead {

class CriticalSection : public IDisposer {
public:
    CriticalSection();

private:
    CriticalSection(const CriticalSection&);
    const CriticalSection& operator=(const CriticalSection&);

public:
    virtual ~CriticalSection();

    void lock();
    bool tryLock();
    void unlock();

protected:
#ifdef cafe
    OSMutex mMutexInner;
#else
#error "Unknown platform"
#endif // cafe
};

} // namespace sead

#endif // SEAD_CRITICAL_SECTION_H_
