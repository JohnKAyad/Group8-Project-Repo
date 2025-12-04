#include <iostream>
#include "DataExport.h"
using namespace std;

void DataExport::writeHeader() const {
    ifstream file_check(outputFilePath.c_str());
    if (!file_check.good()) {
        ofstream outfile(outputFilePath.c_str());
        outfile << "timeStamp,deviceID," << dataName << endl;
        cout << "Created export file: " << outputFilePath << endl;
    }
}

DataExport::DataExport(const string& name, const string& path) : dataName(name), outputFilePath(path) {
    writeHeader();
}

void DataExport::exportRecord(const TelemetryRecord& record) const {
    string metricValue = record.getMetric(dataName);

    ofstream outfile(outputFilePath.c_str(), ios_base::app);

    if (outfile.is_open()) {
        outfile << record.getMetric("timeStamp") << ","
                << record.getMetric("deviceID") << ","
                << metricValue << endl;
    } else {
        cerr << "Error: Could not open file for writing: " << outputFilePath << endl;
    }
}
