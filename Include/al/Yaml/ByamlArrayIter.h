#pragma once

#include "al/Yaml/ByamlData.h"

namespace al {

class ByamlArrayIter {
    const u8* mData;

public:
    ByamlArrayIter(const u8* pData);

    bool getDataByIndex(ByamlData* pData, s32 pIdx);
};

} // namespace al
