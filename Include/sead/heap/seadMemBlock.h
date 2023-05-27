#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/container/seadListImpl.h>
#include <sead/container/seadOffsetList.h>

namespace sead {
class MemBlock {
public:
    static MemBlock* FindManageArea(void* ptr);

    ListNode mListNode;
    size_t mSize;
};

typedef OffsetList<MemBlock> MemBlockList;

} // namespace sead
