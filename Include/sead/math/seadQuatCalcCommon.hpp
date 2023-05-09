#pragma once

#ifndef SEAD_MATH_QUAT_CALC_COMMON_H_
#include <sead/math/seadQuatCalcCommon.h>
#endif

#include <sead/math/seadMathCalcCommon.h>
#include <sead/math/seadQuat.h>

namespace sead {
template <typename T>
inline T QuatCalcCommon<T>::length(const Base& v)
{
    return sqrtf(dot(v, v));
}

template <typename T>
inline T QuatCalcCommon<T>::normalize(Base& v)
{
    const T len = length(v);
    if (len > 0) {
        const T inv_len = 1 / len;
        v.w *= inv_len;
        v.x *= inv_len;
        v.y *= inv_len;
        v.z *= inv_len;
    }

    return len;
}

template <typename T>
inline T QuatCalcCommon<T>::dot(const Base& u, const Base& v)
{
    return (u.w * v.w) + (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}

template <typename T>
inline void QuatCalcCommon<T>::setMul(Base& out, const Base& u, const Base& v)
{
    T w = (u.w * v.w) - (u.x * v.x) - (u.y * v.y) - (u.z * v.z);
    T x = (u.w * v.x) + (u.x * v.w) + (u.y * v.z) - (u.z * v.y);
    T y = (u.w * v.y) - (u.x * v.z) + (u.y * v.w) + (u.z * v.x);
    T z = (u.w * v.z) + (u.x * v.y) - (u.y * v.x) + (u.z * v.w);
    out.w = w;
    out.x = x;
    out.y = y;
    out.z = z;
}

template <typename T>
inline void QuatCalcCommon<T>::makeUnit(Base& q)
{
    q = Quat<T>::unit;
}

template <typename T>
inline bool QuatCalcCommon<T>::makeVectorRotation(Base& q, const Vec3& from, const Vec3& to)
{
    // Based on The Shortest Arc Quaternion from Game Programming Gems 1
    Vec3 cross;
    Vector3CalcCommon<T>::cross(cross, from, to);
    const T dot = Vector3CalcCommon<T>::dot(from, to) + 1;

    if (dot <= MathCalcCommon<T>::epsilon()) {
        makeUnit(q);
        return false;
    } else {
        T s = MathCalcCommon<T>::sqrt(2 * dot);
        T rs = 1 / s;
        set(q, s * 0.5f, cross.x * rs, cross.y * rs, cross.z * rs);
        return true;
    }
}

template <typename T>
inline void QuatCalcCommon<T>::set(Base& q, T w, T x, T y, T z)
{
    q.w = w;
    q.x = x;
    q.y = y;
    q.z = z;
}

template <typename T>
inline void QuatCalcCommon<T>::setRPY(Base& q, T roll, T pitch, T yaw)
{
    const T cy = cosf(yaw / 2);
    const T cp = cosf(pitch / 2);
    const T cr = cosf(roll / 2);
    const T sy = sinf(yaw / 2);
    const T sp = sinf(pitch / 2);
    const T sr = sinf(roll / 2);

    const T cy_cp = cy * cp;
    const T sy_sp = sy * sp;
    const T cy_sp = cy * sp;
    const T sy_cp = sy * cp;

    const T w = (cy_cp * cr) + (sy_sp * sr);
    const T x = (cy_cp * sr) - (sy_sp * cr);
    const T y = (cy_sp * cr) + (sy_cp * sr);
    const T z = (sy_cp * cr) - (cy_sp * sr);

    set(q, w, x, y, z);
}

} // namespace sead
