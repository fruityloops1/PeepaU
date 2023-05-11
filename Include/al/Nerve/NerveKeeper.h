#pragma once

#include "types.h"

namespace al {

class Nerve;
class NerveStateCtrl;
class NerveActionCtrl;

class NerveKeeper;
class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};

class NerveActionCtrl;
class NerveKeeper {
    IUseNerve* mUser;
    const Nerve* mLastNerve;
    const Nerve* mNerve;
    s32 mStep;
    NerveStateCtrl* mNerveStateCtrl;
    NerveActionCtrl* mNerveActionCtrl;

public:
    NerveKeeper(void* user, const Nerve* startNerve, int maxNerveStates = 0);

    void update();
    void setNerve(const Nerve* nrv);
    const Nerve* getCurrentNerve() const;
    void initNerveAction(NerveActionCtrl*);

    IUseNerve* getUser() const { return mUser; }
    s32 getStep() const { return mStep; }
    NerveStateCtrl* getNerveStateCtrl() const { return mNerveStateCtrl; }
    NerveActionCtrl* getNerveActionCtrl() const { return mNerveActionCtrl; }
};

} // namespace al