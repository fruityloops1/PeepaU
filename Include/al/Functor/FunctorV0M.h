#pragma once

#include "al/Functor/FunctorBase.h"

namespace al {

template <class T, class F>
class FunctorV0M : public al::FunctorBase {
    T mParent;
    F mFuncPtr;

public:
    inline FunctorV0M(T parent, F funcPtr)
        : mFuncPtr(funcPtr)
        , mParent(parent)
    {
    }

    void operator()() const { (mParent->*mFuncPtr)(); }
    FunctorV0M* clone() const { return new FunctorV0M<T, F>(mParent, mFuncPtr); }
};

} // namespace al
