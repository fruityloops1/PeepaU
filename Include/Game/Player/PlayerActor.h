#pragma once

#include "Game/Player/Player/Player.h"
#include "Game/Player/PlayerRetargettingSelector.h"
#include "al/LiveActor/LiveActor.h"

class IUsePlayerActionGraphBuilder;
class IUsePlayerRetargettingInfoCreator;

class PlayerActor : public al::LiveActor {

public:
    u8 unk[0x3c];
    Player* mPlayer;

    void initSpecial(const al::ActorInitInfo&, int, const char*, IUsePlayerRetargettingInfoCreator*, IUsePlayerRetargettingSelector*, IUsePlayerActionGraphBuilder*, const char*, unsigned int, int, const char*);
};
