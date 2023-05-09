#pragma once

#include "al/Audio/AudioKeeper.h"
#include <sead/math/seadVectorFwd.h>

namespace al {

class AreaObjDirector;
class CollisionDirector;

class CameraDirector : public IUseAudioKeeper {

public:
    CameraDirector(s32, AreaObjDirector*, CollisionDirector*);
};

class SceneCameraInfo;

class IUseCamera {
public:
    virtual SceneCameraInfo* getSceneCameraInfo() const = 0;
};

} // namespace al
