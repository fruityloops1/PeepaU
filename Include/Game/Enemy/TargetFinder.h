#pragma once

#include "al/LiveActor/LiveActor.h"
#include "types.h"

class TargetFinderParam {
    float _0;
    float _4;
    float _8;
    u32 _C;
    float _10;
    float _14;
    float _18;
    float _1C;
    bool _20;

public:
    TargetFinderParam(float, float, float, u32, float, float, float, float, bool);
};

class TargetFinder {
    al::LiveActor* mHost;
    int _4;
    void* _8;
    void* _C;
    void* _10;
    void* _14;
    TargetFinderParam* mParam;
    void* _1C;

public:
    TargetFinder(al::LiveActor* host, const TargetFinderParam* param);

    void update();

    int get_4() { return _4; } // nonzero when sensor is hit
};
