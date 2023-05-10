#pragma once

#include "types.h"

namespace al {

class ByamlHashPair;

enum ByamlDataType {
    Invalid = 0,
    String = 0xA0,
    Binary = 0xA1,
    Array = 0xC0,
    Hash = 0xC1,
    StringTable = 0xC2,
    Bool = 0xD0,
    Int = 0xD1,
    Float = 0xD2,
    UInt = 0xD3,
    Null = 0xFF
};

class ByamlData {
    union Value {
        s32 vInt;
        u32 vUInt;
        float vFloat;
    } mValue;
    ByamlDataType mType;

public:
    ByamlData();

    void set(const ByamlHashPair* pPair);

    ByamlDataType getType() const { return mType; }

    s32 getIntValue() const { return mValue.vInt; }
    u32 getUIntValue() const { return mValue.vUInt; }
    float getFloatValue() const { return mValue.vFloat; }
};

} // namespace al
