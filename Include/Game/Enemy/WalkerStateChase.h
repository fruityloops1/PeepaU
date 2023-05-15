#pragma once

#include "Game/Enemy/TargetFinder.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/Nerve/NerveStateBase.h"
#include "sead/math/seadVectorFwd.h"
#include "types.h"

class WalkerStateChaseParam {
    u8 _0[0x76]; // ???
public:
    WalkerStateChaseParam(float, float, float, float, float, bool, bool, const char*, const char*, float);
};

class WalkerStateChase : public al::ActorStateBase {
    sead::Vector3f* mActorFront;
    const WalkerStateParam* mWalkerParam;
    const WalkerStateChaseParam* mParam;
    bool _1C;
    bool* _20;
    void* _24;
    TargetFinder* mTargetFinder;

public:
    WalkerStateChase(al::LiveActor* host, sead::Vector3f* hostFront, TargetFinder* targetFinder, const WalkerStateParam* walkerParam, const WalkerStateChaseParam* param, bool, bool* = 0);
};
