#pragma once

#include "al/LiveActor/LiveActor.h"

namespace pe {

class TestActor : public al::LiveActor {
public:
    TestActor(const char* pName);

    virtual void init(const al::ActorInitInfo& pInfo);
};

} // namespace pe
