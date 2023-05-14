#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/Rail/Rail.h"
#include "al/Rail/RailRider.h"

namespace al {

class RailKeeper {
    Rail* mRail;
    RailRider* mRailRider;

public:
    RailKeeper(const PlacementInfo& info);
};

} // namespace al
