#include "Game/Enemy/EnemyStateBlowDown.h"
#include "Game/Enemy/EnemyStateUtil.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "Game/Enemy/WalkerStateRailMove.h"
#include "al/LiveActor/ActorActionFunction.h"
#include "al/LiveActor/ActorInitFunction.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/Math/MathLerpUtil.h"
#include "al/Nerve/NerveUtil.h"
#include "al/Rail/RailUtil.h"
#include "pe/Enemy/Heyho.h"

namespace pe {

namespace {
    NERVE_DEF(Heyho, Wait);
    NERVE_DEF(Heyho, BlowDown);
    NERVE_DEF(Heyho, PressDown);
    NERVE_DEF(Heyho, RailMove);
}

static EnemyStateBlowDownParam sHeyhoBlowDownParam(false);
static WalkerStateParam sHeyhoWalkerParam(1.8, 0.998, 0.92, 500.0, 750.0, 70.0, 80.0, 150.0);
static WalkerStateRailMoveParam sHeyhoRailMoveParam(3);

void Heyho::init(const al::ActorInitInfo& info)
{
    al::initActor(this, info);

    al::initNerve(this, &nrvHeyhoRailMove, 2);

    mStateBlowDown = new EnemyStateBlowDown(this, &sHeyhoBlowDownParam);
    mStateRailMove = new WalkerStateRailMove(this, &sHeyhoWalkerParam, &sHeyhoRailMoveParam);

    al::initNerveState(this, mStateBlowDown, &nrvHeyhoBlowDown, "ボブスレー吹き飛び死亡");
    al::initNerveState(this, mStateRailMove, &nrvHeyhoRailMove, "[state]レール移動");

    makeActorAppeared();
}

bool Heyho::receiveMsg(const al::SensorMsg* msg, al::HitSensor* other, al::HitSensor* me)
{
    if (rc::isMsgBlowDown(msg) && !al::isNerve(this, &nrvHeyhoBlowDown)) {
        rc::tryRequestBlowDownAndNextNerve(msg, other, me, mStateBlowDown, &nrvHeyhoBlowDown);
        return true;
    }

    if (!al::isNerve(this, &nrvHeyhoPressDown)
        && !al::isNerve(this, &nrvHeyhoBlowDown) && rc::tryRequestPressDownAndNextNerve(msg, other, me, this, &nrvHeyhoPressDown))
        return true;
    return false;
}

void Heyho::exeWait()
{
    if (al::isFirstStep(this))
        al::startAction(this, "Wait");

    if (al::isExistRail(this)) {
        al::moveSyncRailLoop(this, 5);
    }

    if (al::isActionEnd(this))
        al::setNerve(this, &nrvHeyhoWait);
}

void Heyho::exeBlowDown()
{
    if (al::updateNerveState(this)) {
        al::startHitReactionDeath(this);
        kill();
    }
}

void Heyho::exePressDown()
{
    if (al::isFirstStep(this))
        al::startAction(this, "PressDown");

    if (al::isActionEnd(this)) {
        al::startHitReactionDeath(this);
        kill();
    }
}

void Heyho::exeRailMove()
{
    al::updateNerveState(this);
}

} // namespace pe
