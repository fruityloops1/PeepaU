#include "Game/Enemy/EnemyStateBlowDown.h"
#include "Game/Enemy/EnemyStateUtil.h"
#include "Game/Enemy/TargetFinder.h"
#include "Game/Enemy/WalkerStateFindPlayer.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "Game/Enemy/WalkerStateRailMove.h"
#include "Game/Enemy/WalkerStateWander.h"
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
    NERVE_DEF(Heyho, Wander);
    NERVE_DEF(Heyho, FindPlayer);
    NERVE_DEF(Heyho, Chase);
}

static EnemyStateBlowDownParam sHeyhoBlowDownParam(false);
static WalkerStateParam sHeyhoWalkerParam(1.8, 0.998, 0.92, 500.0, 750.0, 70.0, 80.0, 150.0);
static WalkerStateRailMoveParam sHeyhoRailMoveParam(3);
static TargetFinderParam sHeyhoTargetFinderParam(750.0, 180.0, 75.0, 90, -1.0, 350.0, 350.0, 750.0, true);
static WalkerStateWanderParam sHeyhoWanderParam(40, 400, 0.3, 0.5, 200.0, 800.0, true, "Walk", "Wait");
static WalkerStateFindPlayerParam sHeyhoFindPlayerParam(30, 7.5, false, "Turn");
static WalkerStateChaseParam sHeyhoChaseParam(0.675, 60.0, 60.0, 3.5, 60.0, true, true, "Run", "Wait", -1);

void Heyho::init(const al::ActorInitInfo& info)
{
    al::initActor(this, info);

    al::initNerve(this, al::isExistRail(this) ? &nrvHeyhoRailMove : (al::Nerve*)&nrvHeyhoWander, 5);

    mStateBlowDown = new EnemyStateBlowDown(this, &sHeyhoBlowDownParam);
    mStateRailMove = new WalkerStateRailMove(this, &sHeyhoWalkerParam, &sHeyhoRailMoveParam);
    mTargetFinder = new TargetFinder(this, &sHeyhoTargetFinderParam);
    mStateWander = new WalkerStateWander(this, al::getFrontPtr(this), &sHeyhoWalkerParam, &sHeyhoWanderParam, mTargetFinder);
    mStateFindPlayer = new WalkerStateFindPlayer(this, al::getFrontPtr(this), mTargetFinder, &sHeyhoWalkerParam, &sHeyhoFindPlayerParam);
    mStateChase = new WalkerStateChase(this, al::getFrontPtr(this), mTargetFinder, &sHeyhoWalkerParam, &sHeyhoChaseParam, true);

    al::initNerveState(this, mStateBlowDown, &nrvHeyhoBlowDown, "ボブスレー吹き飛び死亡");
    al::initNerveState(this, mStateRailMove, &nrvHeyhoRailMove, "レール移動");
    al::initNerveState(this, mStateWander, &nrvHeyhoWander, "うろつき");
    al::initNerveState(this, mStateFindPlayer, &nrvHeyhoFindPlayer, "プレーヤー発見");
    al::initNerveState(this, mStateChase, &nrvHeyhoChase, "追いかけ");

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

    mTargetFinder->update();
    if (mTargetFinder->get_4())
        al::setNerve(this, &nrvHeyhoFindPlayer);
}

void Heyho::exeWander()
{
    al::updateNerveState(this);

    mTargetFinder->update();
    if (mTargetFinder->get_4())
        al::setNerve(this, &nrvHeyhoFindPlayer);
}

void Heyho::exeFindPlayer()
{
    if (al::updateNerveState(this))
        al::setNerve(this, &nrvHeyhoChase);
}

void Heyho::exeChase()
{
    if (al::updateNerveState(this))
        al::setNerve(this, &nrvHeyhoWander);
}

} // namespace pe
