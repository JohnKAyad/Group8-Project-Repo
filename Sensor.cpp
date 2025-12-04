#include "Sensor.h"
#include "Hub.h"
#include "TelemetryRecord.h"
using namespace std;

Sensor::Sensor(const string& id) : deviceID(id) {}

void Sensor::sendToHub(Hub& hub, TelemetryRecord& record) const {
    hub.receive(record);
}

const string& Sensor::getId() const {
    return deviceID;
}
