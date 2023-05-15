#pragma once

#include "Game/Enemy/TargetFinder.h"
#include "Game/Enemy/WalkerStateJump.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/Nerve/NerveStateBase.h"
#include "types.h"
#include <sead/math/seadVectorFwd.h>

class WalkerStateFindPlayerParam {
    u8 _0[0x38];

public:
    WalkerStateFindPlayerParam(int, float, bool, const char*);
};

class WalkerStateFindPlayer : public al::ActorStateBase {
    sead::Vector3f* mActorFront;
    TargetFinder* mTargetFinder;
    const WalkerStateParam* mWalkerParam;
    const WalkerStateFindPlayerParam* mParam;
    void* _20;
    WalkerStateJump* mStateJump;

public:
    WalkerStateFindPlayer(al::LiveActor* host, sead::Vector3f* hostFront, TargetFinder* targetFinder, const WalkerStateParam* walkerParam, const WalkerStateFindPlayerParam* param, const WalkerStateJumpParam* jumpParam = 0);
};
