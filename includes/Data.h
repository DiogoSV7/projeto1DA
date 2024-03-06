#ifndef PROJETO1DA_DATA_H
#define PROJETO1DA_DATA_H

#include <unordered_set>
#include <string>
#include "Graph.h"

template<class T>
class Data {
    public:
        Data();
        void readDeliverySites();
        void readPipes();
        void readPumpingStations();
        void readWaterReservoir();
        Graph<T> getNetwork();
        int maxWaterCity(const std::string& city_code);
    private:
        Graph<T> network_;
};


#endif //PROJETO1DA_DATA_H
