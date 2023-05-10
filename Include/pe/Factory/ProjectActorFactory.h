#pragma once

#include "Game/Factory/ProjectActorFactory.h"

namespace pe {

class ProjectActorFactory : ::ProjectActorFactory {
public:
    ProjectActorFactory();
};

template <typename T>
al::LiveActor* createActorFunction(const char* name)
{
    return new T(name);
}

} // namespace pe
