#pragma once

#include "al/Yaml/ByamlIter.h"

namespace al {

template <typename Creator>
struct NameToCreator {
    const char* name;
    Creator creator;
};

template <typename T>
class Factory {
    const char* mName;
    al::NameToCreator<T>* mEntries;
    int mEntryAmount;

public:
    inline Factory(const char* pFactoryName)
        : mName(pFactoryName)
        , mEntries(0)
        , mEntryAmount(0)
    {
    }
    template <int N>
    inline Factory(const char* pFactoryName, al::NameToCreator<T> (&pEntries)[N])
        : mName(pFactoryName)
    {
        initFactory(pEntries);
    }
    template <int N>
    inline void initFactory(al::NameToCreator<T> (&pEntries)[N])
    {
        mEntries = pEntries;
        mEntryAmount = N;
    }

    virtual const char* convertName(const char* pObjectName) const; // 3D Land leftover
};

} // namespace al
