#pragma once

#include "al/Execute/ExecuteDirector.h"
#include "types.h"

namespace al {

class CollisionDirector : public IUseExecutor {

public:
    CollisionDirector(ExecuteDirector*, s32);
};

class IUseCollision {
public:
    virtual CollisionDirector* getCollisionDirector() const = 0;
};

} // namespace al
