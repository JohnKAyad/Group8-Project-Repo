#include <string>
#include "Constants.h"
using namespace std;

#ifndef HUB_H
#define HUB_H

class Sensor;
class DataExport;
class TelemetryRecord;

class Hub {
    private:
        Sensor* sensors[NUM_SENSORS];
        DataExport* exporters[NUM_EXPORTERS];

        void convertTemp(TelemetryRecord& record);
        void sendToExporter(const TelemetryRecord& record) const;
        
    public:
        Hub();
        ~Hub();

        void receive(TelemetryRecord& record);
        
};
#endif
