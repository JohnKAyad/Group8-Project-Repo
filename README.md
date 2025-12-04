# Group Project

Objectives:
- demonstrate OOP principles
- create a model of dataflow from data collection to storage, facilitated by a central processor (Hub)
- implement data transfer and retrieval, using TelemetryRecord as a Data Transfer Object
- implement data processing, using Hub as a class that receives raw data and performs required calculations
- implement data persistence, using DataExport as a class to ensure each data metric is preserved and isolated

Notes
- Hub uses pointers to have a Composition relationship with Sensor and DataExport
- TelemetryRecord's getMetric function uses an if/else structure to map strings to a data field, which is not scalable. We were not as familiar with using a map to implement this.
- Runtime errors can occur if an invalid dataName for a metric is passed to the 
