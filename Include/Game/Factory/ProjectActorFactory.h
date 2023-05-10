#pragma once

#include "al/Factory/ActorFactory.h"

class ProjectActorFactory : public al::ActorFactory {
public:
    ProjectActorFactory()
        : ActorFactory("アクターファクトリー")
    {
        initFactory(sActorEntries);
    }

    static al::ActorFactoryTableEntry sActorEntries[359];
};
