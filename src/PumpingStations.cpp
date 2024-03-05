
#include "../includes/PumpingStations.h"

using namespace std;
PumpingStations::PumpingStations(int id, string pumping_station_code) : id_(id), pumping_station_code_(pumping_station_code), visited_(false), processing_(false), indegree_(0) {}

int PumpingStations::getId() const {
    return id_;
}

const bool PumpingStations::isVisited() const {
    return visited_;
}

const bool PumpingStations::isProcessing() const {
    return processing_;
}

const int PumpingStations::getIndegree() const {
    return indegree_;
}

const string PumpingStations::getPumpingStationCode() const {
    return pumping_station_code_;
}




