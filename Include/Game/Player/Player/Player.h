#pragma once

#include <sead/math/seadVector.h>

struct PlayerProperty {
    sead::Vector3f mTrans;
    sead::Vector3f mFront;
    sead::Vector3f mUp;
    sead::Vector3f mVelocity;

    u8 _30[0x50];
};

class Player {
public:
    PlayerProperty* mPlayerProperty;
};