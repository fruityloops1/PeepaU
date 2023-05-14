#pragma once

namespace al {

class LiveActor;

void startAction(LiveActor* actor, const char* actionName);
bool tryStartActionIfNotPlaying(LiveActor* actor, const char* actionName);
bool tryStartAction(LiveActor* actor, const char* actionName);

const char* getActionName(const LiveActor* actor);
float getActionFrame(const LiveActor* actor);
bool isActionEnd(const LiveActor* actor);

void startHitReaction(const LiveActor* actor, const char* reactionName);
void startHitReactionDeath(const LiveActor* actor);

} // namespace al
