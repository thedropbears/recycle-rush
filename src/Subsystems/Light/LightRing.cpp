#include "LightRing.h"

LightRing::LightRing(): Subsystem("LightRing") {
    lightRingRelay = new Relay(LIGHT_RING_CHANNEL, Relay::Direction::kForwardOnly);

    lightRingRelay->Set(Relay::Value::kOff);
    time(&timeSinceToggled);
}

LightRing::~LightRing() {
    delete lightRingRelay;
}

void LightRing::ToggleState() {
    time(&timeSinceToggled);
    if(lightRingRelay->Get() == Relay::Value::kOff) {
        lightRingRelay->Set(Relay::Value::kOn);
    } else {
        lightRingRelay->Set(Relay::Value::kOff);
    }
}

void LightRing::Off() {
    lightRingRelay->Set(Relay::Value::kOff);
}

void LightRing::On() {
    lightRingRelay->Set(Relay::Value::kOn);
}
double LightRing::GetTimeSinceToggled() {
    return difftime(time(NULL), timeSinceToggled); // in sec
}
