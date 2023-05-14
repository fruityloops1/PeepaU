#pragma once

#include "Game/Enemy/EnemyStateBlowDown.h"
#include "al/LiveActor/ActorSensorMsgFunction.h"

namespace rc {

bool isMsgBlowDown(const al::SensorMsg* msg);
void requestBlowDown(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me, EnemyStateBlowDown* state, bool appearItem = false);
bool tryRequestBlowDown(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me, EnemyStateBlowDown* state, bool appearItem = false);
bool tryRequestBlowDownAndNextNerve(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me, EnemyStateBlowDown* state, const al::Nerve* nextNrv, bool appearItem = false);

bool isMsgPressDownForCrossoverSensor(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me);
bool tryRequestPressDown(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me, bool appearItem = false);
bool tryRequestPressDownAndNextNerve(const al::SensorMsg* msg, const al::HitSensor* other, const al::HitSensor* me, al::LiveActor* actor, const al::Nerve* nextNrv, bool appearItem = false);

} // namespace rc
