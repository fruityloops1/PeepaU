#pragma once

#include "al/Yaml/ByamlIter.h"

namespace al {

class PlacementInfo {
    ByamlIter mPlacementIter;
    ByamlIter mZoneIter;

public:
    PlacementInfo();

    const ByamlIter& getPlacementIter() const { return mPlacementIter; }
    const ByamlIter& getZoneIter() const { return mZoneIter; }
};

} // namespace al
