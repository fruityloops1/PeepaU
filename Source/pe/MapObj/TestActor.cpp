#include "al/LiveActor/ActorInitFunction.h"
#include "pe/MapObj/TestActor.h"

namespace pe {

TestActor::TestActor(const char* pName)
    : LiveActor(pName)
{
}

void TestActor::init(const al::ActorInitInfo& pInfo)
{
    // crashe
    al::initActorWithArchiveName(this, pInfo, "Coin");

    makeActorAppeared();
}

} // namespace pe
