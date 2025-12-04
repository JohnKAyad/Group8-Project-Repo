#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include "TelemetryRecord.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include "TelemetryRecord.h"

TelemetryRecord::TelemetryRecord(double timeStamp, const string& deviceID, double carbonMLevel, double humidity, bool light, double liquidPGasLevel, bool motion, double smoke, double tempF) :
timeStamp(timeStamp), deviceID(deviceID), carbonMLevel(carbonMLevel), humidity(humidity), light(light), liquidPGasLevel(liquidPGasLevel), motion(motion), smoke(smoke), tempF(tempF), tempC(0.0) {}

void TelemetryRecord::setTempC(double c_value) {
    tempC = c_value;
}

string TelemetryRecord::toString(double val) const {
    ostringstream oss;
    oss << val;
    return oss.str();
}
string TelemetryRecord::getMetric(const string& dataName) const {
    if (dataName == "timeStamp") return toString(timeStamp);
    else if (dataName == "deviceID") return deviceID;
    else if (dataName == "carbonMLevel") return toString(carbonMLevel);
    else if (dataName == "humidity") return toString(humidity);
    else if (dataName == "light") return light ? "true" : "false";
    else if (dataName == "liquidPGasLevel") return toString(liquidPGasLevel);
    else if (dataName == "motion") return motion ? "true" : "false";
    else if (dataName == "smoke") return toString(smoke);
    else if (dataName == "tempF") return toString(tempF);
    else if (dataName == "tempC") return toString(tempC);
    else {
        throw std::runtime_error("Invalid metric name requested: " + dataName);
    }
}
TelemetryRecord::TelemetryRecord(double timeStamp, const string& deviceID, double carbonMLevel, double humidity, bool light, double liquidPGasLevel, bool motion, double smoke, double tempF) :
timeStamp(timeStamp), deviceID(deviceID), carbonMLevel(carbonMLevel), humidity(humidity), light(light), liquidPGasLevel(liquidPGasLevel), motion(motion), smoke(smoke), tempF(tempF), tempC(0.0) {}

void TelemetryRecord::setTempC(double c_value) {
    tempC = c_value;
}

string TelemetryRecord::toString(double val) const {
    ostringstream oss;
    oss << val;
    return oss.str();
}
string TelemetryRecord::getMetric(const string& metricName) const {
    if (metricName == "timeStamp") return toString(timeStamp);
    else if (metricName == "deviceID") return deviceID;
    else if (metricName == "carbonMLevel") return toString(carbonMLevel);
    else if (metricName == "humidity") return toString(humidity);
    else if (metricName == "light") return light ? "true" : "false";
    else if (metricName == "liquidPGasLevel") return toString(liquidPGasLevel);
    else if (metricName == "motion") return motion ? "true" : "false";
    else if (metricName == "smoke") return toString(smoke);
    else if (metricName == "tempF") return toString(tempF);
    else if (metricName == "tempC") return toString(tempC);
    else {
        throw std::runtime_error("Invalid metric name requested: " + metricName);
    }
}
