#pragma once

#include "al/Factory/ActorFactory.h"

class ProjectActorFactory : public al::ActorFactory {
public:
    ProjectActorFactory();

    static al::ActorFactoryTableEntry sActorEntries[359];
};
