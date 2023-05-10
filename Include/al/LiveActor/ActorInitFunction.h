#pragma once

#include <sead/prim/seadSafeString.h>

namespace al {

class ActorInitInfo {

public:
    ActorInitInfo();
};

class LiveActor;

void initActorPoseTFGSV(LiveActor* pActor);
void initActorPoseTFSV(LiveActor* pActor);
void initActorPoseTQSV(LiveActor* pActor);
void initActorPoseTRMSV(LiveActor* pActor);
void initActorPoseTRSV(LiveActor* pActor);
void initActorSRT(LiveActor* pActor, const ActorInitInfo& pInfo);

void initActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* suffix = 0);

} // namespace al
