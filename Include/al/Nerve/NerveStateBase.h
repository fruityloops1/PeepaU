#pragma once

#include "al/Nerve/NerveExecutor.h"

namespace al {

class NerveStateBase : public NerveExecutor {
    bool mIsDead;

public:
    NerveStateBase(const char* pName);
    virtual ~NerveStateBase();

    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    bool isDead() const { return mIsDead; }
};

class LiveActor;
class ActorStateBase : public NerveStateBase {
protected:
    LiveActor* mHost;

public:
    ActorStateBase(const char* pName, LiveActor* pHost);
    virtual ~ActorStateBase();
};

} // namespace al
