#include "al/LiveActor/ActorInitFunction.h"
#include "pe/MapObj/TestActor.h"

namespace pe {

TestActor::TestActor(const char* name)
    : LiveActor(0, name)
{
}

void TestActor::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "FairyPrincess06");

    makeActorAppeared();
}

} // namespace pe
