#pragma once

#include "sead/math/seadVector.h"

namespace al {

class RailRider {
    void* _0;
    sead::Vector3f mPos;
    sead::Vector3f mDir;

public:
};

class IUseRail {
    virtual RailRider* getRailRider() const = 0;
};

} // namespace al
