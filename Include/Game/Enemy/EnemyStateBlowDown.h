#pragma once

#include "al/LiveActor/LiveActorFlag.h"
#include "al/Nerve/NerveStateBase.h"
#include "sead/math/seadVector.h"

struct EnemyStateBlowDownParam {
    const char* actionName;
    float _4;
    float _8;
    float _C;
    float _10;
    float _14;

    EnemyStateBlowDownParam(bool isUnderWater);
};

class EnemyStateBlowDown : public al::ActorStateBase {
    EnemyStateBlowDownParam* mParam;
    sead::Vector3f _20;

public:
    EnemyStateBlowDown(al::LiveActor* host, const EnemyStateBlowDownParam* param);
};
