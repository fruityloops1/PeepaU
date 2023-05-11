#pragma once

#include "al/Yaml/ByamlIter.h"
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVectorFwd.h>

namespace al {

class ActorInitInfo;
class PlacementId;
class PlacementInfo;

bool isPlaced(const ActorInitInfo& info);
void getObjectName(const char** out, const ActorInitInfo& info);
bool tryGetObjectName(const char** out, const ActorInitInfo& info);
bool tryGetStringArg(const char** out, const ActorInitInfo& info, const char* key);
bool isObjectName(const ActorInitInfo& info, const char* name);
bool isObjectNameSubStr(const ActorInitInfo& info, const char* subStr);
bool tryGetClassName(const char** out, const PlacementInfo& info);
bool tryGetPlacementInfoByKey(PlacementInfo* out, const PlacementInfo& info, const char* key);
void getClassName(const char** out, const ActorInitInfo& info);
bool isClassName(const ActorInitInfo& info, const char* pClassName);
bool isClassName(const PlacementInfo& info, const char* pClassName);
void getDisplayName(const char** out, const ActorInitInfo& info);
void getDisplayName(const char** out, const PlacementInfo& info);
bool tryGetDisplayName(const char** out, const PlacementInfo& info);
bool tryGetTrans(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetTrans(sead::Vector3f* out, const PlacementInfo& info);
void getTrans(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetZoneMatrixTR(sead::Matrix34f* out, const PlacementInfo& info);
bool tryGetRotate(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetRotate(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetZoneR(sead::Vector3f* out, const PlacementInfo& info);
void getRotate(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetQuat(sead::Quatf* out, const ActorInitInfo& info);
bool tryGetQuat(sead::Quatf* out, const PlacementInfo& info);
void getQuat(sead::Quatf* out, const PlacementInfo& info);
bool tryGetScale(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetScale(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetSide(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetSide(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetUp(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetUp(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetFront(sead::Vector3f* out, const ActorInitInfo& info);
bool tryGetFront(sead::Vector3f* out, const PlacementInfo& info);
bool tryGetLocalAxis(sead::Vector3f* out, const ActorInitInfo& info, int pAxis);
bool tryGetLocalAxis(sead::Vector3f* out, const PlacementInfo& info, int pAxis);

bool tryGetArg(float* out, const al::ActorInitInfo& info, const char* key);
bool tryGetArg(bool* out, const al::ActorInitInfo& info, const char* key);

int calcLinkChildNum(const al::ActorInitInfo& info, const char* linkName);
void getLinksInfo(PlacementInfo* out, const PlacementInfo& parentInfo, const char* linkName);

} // namespace al

namespace alPlacementFunction {

void getClippingViewId(al::PlacementId* out, const al::PlacementInfo& info);

} // namespace alPlacementFunction
