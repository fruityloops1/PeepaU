#include "pe/Enemy/Foomin.h"
#include "pe/Enemy/Heyho.h"
#include "pe/Factory/ProjectActorFactory.h"
#include "pe/MapObj/TestActor.h"

class Coin;

namespace pe {

static al::ActorFactoryTableEntry customActorEntries[] = {
    { "TestActor", pe::createActorFunction<TestActor> },
    { "Foomin", pe::createActorFunction<Foomin> },
    { "Heyho", pe::createActorFunction<Heyho> }
};

pe::ProjectActorFactory::ProjectActorFactory()
{
    const size_t customActorEntriesSize = sizeof(customActorEntries) / sizeof(al::ActorFactoryTableEntry);
    const size_t actorEntriesSize = sizeof(::ProjectActorFactory::sActorEntries) / sizeof(al::ActorFactoryTableEntry);

    static al::ActorFactoryTableEntry outEntries[customActorEntriesSize + actorEntriesSize];
    static bool isInitialized = false;

    if (!isInitialized) {
        int i = 0;

        for (int j = 0; j < customActorEntriesSize; j++) {
            outEntries[i] = customActorEntries[j];
            i++;
        }

        for (int j = 0; j < actorEntriesSize; j++) {
            outEntries[i] = sActorEntries[j];
            i++;
        }

        isInitialized = true;
    }

    initFactory(outEntries);
}

} // namespace pe
