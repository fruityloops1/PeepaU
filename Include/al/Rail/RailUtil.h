#pragma once

#include <sead/math/seadVectorFwd.h>

namespace al {

class LiveActor;

bool isExistRail(const LiveActor* actor);

void syncRailTrans(const LiveActor* actor);

bool moveRailLoop(const LiveActor* actor, float speed);
bool moveSyncRailLoop(const LiveActor* actor, float speed);

const sead::Vector3f& getRailPos(const LiveActor* actor);
const sead::Vector3f& getRailDir(const LiveActor* actor);

} // namespace al
