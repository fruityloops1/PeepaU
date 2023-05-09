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
    NerveStateCtrl(int pMaxNerveStates);

    void addState(NerveStateBase* pState, const Nerve* pNrv, const char* pName);
    bool updateCurrentState();
    void startState(const Nerve* pNrv);
    State* findStateInfo(const Nerve* pNrv);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();
};

} // namespace al