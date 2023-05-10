#pragma once

#include "al/LiveActor/LiveActor.h"

namespace pe {

class TestActor : public al::LiveActor {
public:
    TestActor(const char* name);

    virtual void init(const al::ActorInitInfo& info);
};

} // namespace pe
