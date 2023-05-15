#pragma once

#include "Game/Enemy/EnemyStateBlowDown.h"
#include "Game/Enemy/WalkerStateChase.h"
#include "Game/Enemy/WalkerStateFindPlayer.h"
#include "Game/Enemy/WalkerStateRailMove.h"
#include "Game/Enemy/WalkerStateWander.h"
#include "al/LiveActor/LiveActor.h"

namespace pe {

class Heyho : public al::LiveActor {
    EnemyStateBlowDown* mStateBlowDown;
    WalkerStateRailMove* mStateRailMove;
    WalkerStateWander* mStateWander;
    WalkerStateFindPlayer* mStateFindPlayer;
    WalkerStateChase* mStateChase;
    TargetFinder* mTargetFinder;

public:
    Heyho(const char* name)
        : LiveActor(0, name)
        , mStateBlowDown(0)
        , mStateRailMove(0)
        , mStateWander(0)
        , mStateFindPlayer(0)
        , mStateChase(0)
        , mTargetFinder(0)
    {
    }

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* me);

    void exeWait();
    void exeBlowDown();
    void exePressDown();
    void exeRailMove();
    void exeWander();
    void exeFindPlayer();
    void exeChase();
};

} // namespace pe
