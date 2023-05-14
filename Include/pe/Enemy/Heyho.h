#pragma once

#include "Game/Enemy/EnemyStateBlowDown.h"
#include "Game/Enemy/WalkerStateRailMove.h"
#include "al/LiveActor/LiveActor.h"

namespace pe {

class Heyho : public al::LiveActor {
    EnemyStateBlowDown* mStateBlowDown;
    WalkerStateRailMove* mStateRailMove;

public:
    Heyho(const char* name)
        : LiveActor(0, name)
        , mStateBlowDown(0)
        , mStateRailMove(0)
    {
    }

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* me);

    void exeWait();
    void exeBlowDown();
    void exePressDown();
    void exeRailMove();
};

} // namespace pe
