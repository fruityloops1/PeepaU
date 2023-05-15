#pragma once

#include "Game/Enemy/TargetFinder.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/Nerve/NerveStateBase.h"
#include <sead/math/seadVectorFwd.h>

class TerritoryMover;

class WalkerStateWanderParam {
    u8 _0[0x76]; // ???
public:
    WalkerStateWanderParam(int, int, float, float, float, float, bool, const char*, const char*);
};

class WalkerStateWander : public al::ActorStateBase {
    sead::Vector3f* mActorFront;
    TerritoryMover* mTerritoryMover;
    const WalkerStateParam* mWalkerParam;
    const WalkerStateWanderParam* mParam;
    TargetFinder* mTargetFinder;

public:
    WalkerStateWander(al::LiveActor* host, sead::Vector3f* hostFront, const WalkerStateParam* walkerParam, const WalkerStateWanderParam* param, TargetFinder* targetFinder);
};
