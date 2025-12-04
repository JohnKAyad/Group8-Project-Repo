#include <string>
#include <sstream>
using namespace std;

#ifndef TELEMETRYRECORD_H
#define TELEMETRYRECORD_H

class TelemetryRecord {
    private:
        double timeStamp;
        string deviceID;
        double carbonMLevel;
        double humidity;
        bool light;
        double liquidPGasLevel;
        bool motion;
        double smoke;
        double tempF;
        double tempC;

        string toString(double val) const;

    public:
        TelemetryRecord(double timeStamp, const string& deviceID, double carbonMLevel, double humidity, bool light, double liquidPGasLevel, bool motion, double smoke, double tempF);

        void setTempC(double c_value);

        string getMetric(const string& dataName) const;

};
#endif
