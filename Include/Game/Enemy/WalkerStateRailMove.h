#pragma once

#include "Game/Enemy/WalkerStateParam.h"
#include "al/Nerve/NerveStateBase.h"
#include "types.h"
#include <sead/math/seadVector.h>

class WalkerStateRailMoveParam {
    u8 _0[0x76]; // ???
public:
    WalkerStateRailMoveParam(float moveSpeed);
};

class WalkerStateRailMove : public al::ActorStateBase {
    const WalkerStateParam* mWalkerParam;
    const WalkerStateRailMoveParam* mParam;
    void* _18;
    void* _1C;
    void* _20;
    sead::Vector3f _24;
    float mClippingRadius, mClippingRadius2;

public:
    WalkerStateRailMove(al::LiveActor* host, const WalkerStateParam* walkerParam, const WalkerStateRailMoveParam* param);

    void setPositionToStart();
};
