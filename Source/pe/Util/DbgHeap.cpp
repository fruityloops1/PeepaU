#include "pe/Util/DbgHeap.h"

namespace pe {

static sead::ExpHeap* sHeap = NULL;

sead::ExpHeap*& getDbgHeap()
{
    return sHeap;
}

} // namespace pe
