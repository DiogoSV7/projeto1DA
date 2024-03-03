#ifndef PROJETO1DA_DATA_H
#define PROJETO1DA_DATA_H

#include <unordered_set>
#include <string>
#include "Graph.h"

class Data {
    public:
        Data();
        void readDeliverySites();
        void readPipes();
        void readPumpingStations();
        void readWaterReservoir();
        Graph getNetwork();
    private:
        Graph network_;
};


#endif //PROJETO1DA_DATA_H
