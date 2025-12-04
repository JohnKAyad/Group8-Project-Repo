#include <iomanip>
#include <string>
#include "Hub.h"
#include "Sensor.h"
#include "DataExport.h"
#include "TelemetryRecord.h"
using namespace std;

Hub::Hub() {
    const string device_ids[NUM_SENSORS] = {
        "00:0f:00:70:91:0a", "1c:bf:ec:15:ec:4d", "b8:27:eb:bf:9d:51"
    };

    for (int i = 0; i < NUM_SENSORS; ++i) {
        sensors[i] = new Sensor(device_ids[i]);
    }
    cout << "Hub initialized with " << NUM_SENSORS << " Sensors." << endl;

    const string metric_list[NUM_EXPORTERS] = {
        "co", "humidity", "light", "lpg", "motion", "smoke", "tempC"
    };

    for (int i = 0; i < NUM_EXPORTERS; ++i) {
        string filename = "output_" + metric_list[i] + ".csv";
        exporters[i] = new DataExport(metric_list[i], filename);
    }
    cout << "Hub initialized with " << NUM_EXPORTERS << " MetricExporters." << endl;
}

Hub::~Hub() {
    for (int i = 0; i < NUM_SENSORS; ++i) {
        delete sensors[i];
    }

    for (int i = 0; i < NUM_EXPORTERS; ++i) {
        delete exporters[i];
    }

    cout << "Hub cleaned up memory." << endl;
}

void Hub::convertTemp(TelemetryRecord& record) {
    double tempF = atof(record.getMetric("tempF").c_str());
    double tempC = (tempF - 32.0) * (5.0/9.0);
    record.setTempC(tempC);
}

void Hub::sendToExporter(const TelemetryRecord& record) const {
    for (int i = 0; i < NUM_EXPORTERS; ++i) {
        exporters[i]->exportRecord(record);
    }
}

void Hub::receive(TelemetryRecord& record) {
    convertTemp(record);

    sendToExporter(record);

    cout << "Hub processed record from " << record.getMetric("deviceID");
    cout << ", Temp C: " << fixed << setprecision(2) << record.getMetric("tempC") << endl;
}

