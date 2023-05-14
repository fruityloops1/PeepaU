#pragma once

#include "al/AreaObj/AreaObjDirector.h"
#include "al/Audio/AudioKeeper.h"
#include "al/Camera/CameraDirector.h"
#include "al/Collision/CollisionDirector.h"
#include "al/Effect/EffectKeeper.h"
#include "al/LiveActor/LiveActorFlag.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Scene/SceneObjHolder.h"
#include "al/StageSwitch/StageSwitchKeeper.h"

namespace al {

class Unknown {
public:
    virtual void unk();
};

class ActorPoseKeeperBase;
class ModelKeeper;
class NerveKeeper;
class RailKeeper;
class SubActorKeeper;
class ActorSceneInfo;
class SensorMsg;
class HitSensor;
class ScreenPointDirector;
class ScreenPointTarget;
class ScreenPointer;
class ShadowKeeper;
class ActorParamHolder;
class HitReactionKeeper;
class ScreenPointKeeper;
class HitSensorKeeper;
class CollisionParts;
class ActorScoreKeeper;
class ActorItemKeeper;
class ActorActionKeeper;
class ActorExecuteInfo;
class Collider;
class ActorPrePassLightKeeper;

class LiveActor : public IUseNerve,
                  public IUseEffectKeeper,
                  public IUseAudioKeeper,
                  public IUseStageSwitch,
                  Unknown,
                  public IUseSceneObjHolder,
                  public IUseAreaObj,
                  public IUseCamera,
                  public IUseCollision {
protected:
    const char* const mName;
    ActorPoseKeeperBase* mActorPoseKeeper;
    ActorExecuteInfo* mExecuteInfo;
    ActorActionKeeper* mActionKeeper;
    ActorItemKeeper* mItemKeeper;
    ActorScoreKeeper* mScoreKeeper;
    Collider* mCollider;
    CollisionParts* mCollisionParts;
    ModelKeeper* mModelKeeper;
    NerveKeeper* mNerveKeeper;
    HitSensorKeeper* mHitSensorKeeper;
    ScreenPointKeeper* mScreenPointKeeper;
    EffectKeeper* mEffectKeeper;
    AudioKeeper* mAudioKeeper;
    HitReactionKeeper* mHitReactionKeeper;
    StageSwitchKeeper* mStageSwitchKeeper;
    RailKeeper* mRailKeeper;
    ShadowKeeper* mShadowKeeper;
    ActorPrePassLightKeeper* mPrePassLightKeeper;
    SubActorKeeper* mSubActorKeeper;
    ActorParamHolder* mParamHolder;
    ActorSceneInfo* mActorSceneInfo;
    LiveActorFlag* mLiveActorFlag;

    const void* weirdVtbl;

public:
    LiveActor(const void* /* garbage */, const char* name);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual void init(const ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void draw();
    virtual void startClipped();
    virtual void endClipped();
    virtual void attackSensor(HitSensor* me, HitSensor* other);
    virtual bool receiveMsg(const SensorMsg* msg, HitSensor* other, HitSensor* me);
    virtual bool receiveMsgScreenPoint(const SensorMsg* msg, ScreenPointer* pointer, ScreenPointTarget* target);
    virtual const char* getName() const;
    virtual sead::Matrix34f* getBaseMtx() const;
    virtual EffectKeeper* getEffectKeeper() const;
    virtual AudioKeeper* getAudioKeeper() const;
    virtual StageSwitchKeeper* getStageSwitchKeeper() const;
    virtual SceneObjHolder* getSceneObjHolder() const;
    virtual CollisionDirector* getCollisionDirector() const;
    virtual AreaObjDirector* getAreaObjDirector() const;
    virtual SceneCameraInfo* getSceneCameraInfo() const;
    virtual void initStageSwitchKeeper();
    virtual void control();
    virtual void unk();
    virtual void FUN_02414d4c();

    void initItemKeeper(int);
    void initModelKeeper(ModelKeeper*);
    void initNerve(const Nerve* nrv, int maxNerveStates = 0);
    void initNerveKeeper(NerveKeeper*);
    void initPoseKeeper(ActorPoseKeeperBase*);
    void initRailKeeper(const ActorInitInfo& info);
    void initSceneInfo(ActorSceneInfo* info);
    void initScoreKeeper();
    void initScreenPointKeeper(int);

    ActorPoseKeeperBase* getActorPoseKeeper() const { return mActorPoseKeeper; }
    ActorSceneInfo* getActorSceneInfo() const { return mActorSceneInfo; }
    HitSensorKeeper* getHitSensorKeeper() const { return mHitSensorKeeper; }
    ModelKeeper* getModelKeeper() const { return mModelKeeper; }
    SubActorKeeper* getSubActorKeeper() const { return mSubActorKeeper; }
    LiveActorFlag* getLiveActorFlag() const { return mLiveActorFlag; }
};

} // namespace al
