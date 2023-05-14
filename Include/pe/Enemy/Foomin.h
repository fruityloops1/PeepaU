#pragma once

#include "Game/Player/PlayerActor.h"
#include "al/LiveActor/LiveActor.h"

namespace pe {

// this is a shittily written actor, do not use it as example material
class Foomin : public al::LiveActor {
    const static int sFlipStartFrame = 60, sFlipEndFrame = 90;

    float pFlingVelocityMultiplier;
    float pFlingYVelocityMultiplier;
    bool pMoveLeftRight;
    float pMoveAmount;
    float pMoveSpeed;

    bool mMoveDir;
    int mMoveAmount;
    int mFramesUntilCollisionPartsReactivate;
    int mFramesSinceLaunch;
    PlayerActor* mPlayerActor;

    void invalidateCollisionParts();

public:
    Foomin(const char* name)
        : LiveActor(0, name)
        , pFlingVelocityMultiplier(20)
        , pFlingYVelocityMultiplier(20)
        , pMoveLeftRight(false)
        , pMoveAmount(500)
        , pMoveSpeed(10)
        , mMoveDir(false)
        , mMoveAmount(0)
        , mFramesUntilCollisionPartsReactivate(20)
        , mFramesSinceLaunch(-1)
    {
    }

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* me);
    virtual void control();

    void exeWait();
    void exeFlip();
};

} // namespace pe