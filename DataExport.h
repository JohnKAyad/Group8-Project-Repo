#include <string>
#include <fstream>
#include <iostream>
#include "TelemetryRecord.h"
using namespace std;

#ifndef DATAEXPORT_H
#define DATAEXPORT_H

class DataExport {
    private:
        string dataName;
        string outputFilePath;

        void writeHeader() const;

    public:
        DataExport(const string& name, const string& path);

        void exportRecord(const TelemetryRecord& record) const;
};
#endif
