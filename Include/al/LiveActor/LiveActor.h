#pragma once

#include "al/AreaObj/AreaObjDirector.h"
#include "al/Audio/AudioKeeper.h"
#include "al/Camera/CameraDirector.h"
#include "al/Collision/CollisionDirector.h"
#include "al/Effect/EffectKeeper.h"
#include "al/LiveActor/LiveActorFlag.h"
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
    void* _2C;
    void* _30;
    void* _34;
    void* _38;
    void* _3C;
    void* _40;
    ModelKeeper* mModelKeeper;
    NerveKeeper* mNerveKeeper;
    void* _4C;
    void* _50;
    EffectKeeper* mEffectKeeper;
    AudioKeeper* mAudioKeeper;
    void* _5C;
    StageSwitchKeeper* mStageSwitchKeeper;
    RailKeeper* mRailKeeper;
    void* _68;
    void* _6C;
    SubActorKeeper* mSubActorKeeper;
    void* _74;
    ActorSceneInfo* mActorSceneInfo;
    LiveActorFlag* mLiveActorFlag;
    const void* weirdVtbl;

public:
    LiveActor(const void*, const char* name);

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
    virtual void receiveMsg(const SensorMsg* msg, HitSensor* other, HitSensor* me);
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

    void initModelKeeper(ModelKeeper*);
    void initNerveKeeper(NerveKeeper*);
    void initPoseKeeper(ActorPoseKeeperBase*);
    void initRailKeeper(const ActorInitInfo& info);

    ActorPoseKeeperBase* getActorPoseKeeper() const { return mActorPoseKeeper; }
    SubActorKeeper* getSubActorKeeper() const { return mSubActorKeeper; }
    LiveActorFlag* getLiveActorFlag() const { return mLiveActorFlag; }
};

} // namespace al
