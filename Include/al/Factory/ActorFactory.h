#pragma once

#include "al/Factory/Factory.h"

namespace al {

class LiveActor;

typedef al::LiveActor* (*CreateActorFunctionType)(const char*);
typedef NameToCreator<CreateActorFunctionType> ActorFactoryTableEntry;

class ActorFactory : public Factory<CreateActorFunctionType> {
    ByamlIter mConvertNameTable;

public:
    ActorFactory(const char* name);
};

template <typename T>
LiveActor* createActorFunction(const char* name);

} // namespace al
