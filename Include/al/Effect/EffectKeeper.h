#pragma once

#include <sead/math/seadMatrix.h>
#include <sead/math/seadVectorFwd.h>

namespace al {

class EffectSystemInfo;
class MtxPtrHolder;

class EffectKeeper {

public:
    EffectKeeper(const EffectSystemInfo*, const char* userName, const sead::Vector3f*, const sead::Vector3f*, const sead::Matrix34f*);
};

class IUseEffectKeeper {
public:
    virtual EffectKeeper* getEffectKeeper() const = 0;
};

void tryDeleteEffect(IUseEffectKeeper* user, const char* effectName);

} // namespace al
