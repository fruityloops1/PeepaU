#pragma once

#include "al/Nerve/Nerve.h"
#include "types.h"

namespace al {

class NerveStateBase;
class NerveStateCtrl {
public:
    struct State {
        NerveStateBase* mState;
        const Nerve* mHostStateNrv;
        const char* mName;
    };

private:
    s32 mCapacity;
    s32 mNumStates;
    State* mStates;
    State* mCurrentState;

public:
    NerveStateCtrl(int maxNerveStates);

    void addState(NerveStateBase* state, const Nerve* nrv, const char* name);
    bool updateCurrentState();
    void startState(const Nerve* nrv);
    State* findStateInfo(const Nerve* nrv);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();
};

} // namespace al