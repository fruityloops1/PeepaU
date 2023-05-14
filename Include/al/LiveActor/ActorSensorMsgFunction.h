#pragma once

namespace al {

class HitSensor;

class SensorMsg {
};

bool isMsgPlayerFloorTouch(const SensorMsg* msg);
bool isMsgTouchAssist(const SensorMsg* msg);
void isMsgBallAttack(const SensorMsg* msg);
void isMsgBallAttackHold(const SensorMsg* msg);
void isMsgBallAttackDRCHold(const SensorMsg* msg);
void isMsgBlockUpperPunch(const SensorMsg* msg);
void isMsgEnemyAttackFire(const SensorMsg* msg);
void isMsgEnemyAttackBoomerang(const SensorMsg* msg);
void isMsgExplosion(const SensorMsg* msg);
void isMsgKickKouraAttack(const SensorMsg* msg);
void isMsgKickStoneAttack(const SensorMsg* msg);
void isMsgKillerAttack(const SensorMsg* msg);
void isMsgPlayerBodyAttack(const SensorMsg* msg);
void isMsgPlayerBodyLanding(const SensorMsg* msg);
void isMsgPlayerBoomerangAttack(const SensorMsg* msg);
void isMsgPlayerClimbAttack(const SensorMsg* msg);
void isMsgPlayerCooperationHipDrop(const SensorMsg* msg);
void isMsgPlayerFireBallAttack(const SensorMsg* msg);
void isMsgPlayerGiantAttack(const SensorMsg* msg);
void isMsgPlayerGiantHipDrop(const SensorMsg* msg);
void isMsgPlayerInvincibleAttack(const SensorMsg* msg);
void isMsgPlayerKouraAttack(const SensorMsg* msg);
void isMsgPlayerSlidingAttack(const SensorMsg* msg);
void isMsgPlayerTailAttack(const SensorMsg* msg);
void isMsgPlayerSpinAttack(const SensorMsg* msg);

bool isSensorPlayer(const HitSensor*);

} // namespace al
