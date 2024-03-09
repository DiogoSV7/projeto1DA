
#include <utility>

#include "../includes/PumpingStations.h"

using namespace std;
PumpingStations::PumpingStations(int id, string pumping_station_code) : id_(id), pumping_station_code_(std::move(pumping_station_code)){}

int PumpingStations::getId() const {
    return id_;
}

const string PumpingStations::getPumpingStationCode() const {
    return pumping_station_code_;
}




