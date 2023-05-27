#include <sead/heap/seadFrameHeap.h>

namespace sead {

size_t FrameHeap::getFreeSize() const
{

    if (mFlag.isOn(1)) {
        ((FrameHeap*)this)->mCS.lock();
    }

    size_t freeSize = ptrdiff_t(state.mTailPtr) - ptrdiff_t(state.mHeadPtr);

    ((FrameHeap*)this)->mCS.unlock();
    return freeSize;
}

} // namespace sead
