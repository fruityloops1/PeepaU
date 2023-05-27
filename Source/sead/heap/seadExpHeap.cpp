#include <sead/heap/seadExpHeap.h>

namespace sead {

size_t ExpHeap::getFreeSize() const
{
    if (mFlag.isOn(1)) {
        ((ExpHeap*)this)->mCS.lock();
    }

    size_t freeSize = 0;
    for (sead::OffsetList<sead::MemBlock>::iterator it = mFreeList.begin(); it != mFreeList.end(); ++it) {
        freeSize += it->mSize;
    }

    ((ExpHeap*)this)->mCS.unlock();
    return freeSize;
}

} // namespace sead
