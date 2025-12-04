#include <string>
using namespace std;

#ifndef SENSOR_H
#define SENSOR_H

class Hub;
class TelemetryRecord;

class Sensor {
    private:
        string deviceID;
        
    public:
        Sensor(const string& id);

        void sendToHub(Hub& hub, TelemetryRecord& record) const;

        const string& getId() const;
};
#endif
