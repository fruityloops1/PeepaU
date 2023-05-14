#pragma once

namespace al {

class LiveActor;
class HitSensor;

HitSensor* getHitSensor(const LiveActor* actor, const char* sensorName);
LiveActor* getSensorHost(const HitSensor* sensor);

} // namespace al
