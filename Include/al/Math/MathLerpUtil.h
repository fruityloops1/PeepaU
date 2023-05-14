#pragma once

#include <sead/math/seadVectorFwd.h>

namespace al {

void lerpVec(sead::Vector3f* out, const sead::Vector3f& min, const sead::Vector3f& max, float amount);
void lerpVec(sead::Vector2f* out, const sead::Vector2f& min, const sead::Vector2f& max, float amount);

} // namespace al
