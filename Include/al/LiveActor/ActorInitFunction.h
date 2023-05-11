#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {

class ActorInitInfo {

public:
    ActorInitInfo();
};

class LiveActor;

void initActorPoseTFGSV(LiveActor* actor);
void initActorPoseTFSV(LiveActor* actor);
void initActorPoseTQSV(LiveActor* actor);
void initActorPoseTRMSV(LiveActor* actor);
void initActorPoseTRSV(LiveActor* actor);
void initActorSRT(LiveActor* actor, const ActorInitInfo& info);

void initActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* suffix = 0);

} // namespace al
