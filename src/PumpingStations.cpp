
#include "../includes/PumpingStations.h"

using namespace std;
PumpingStations::PumpingStations(int id, string pumping_station_code) {
    this->pumping_station_code_=pumping_station_code;
    this->id_=id;

}

int PumpingStations::getId() const {
    return id_;
}

const string PumpingStations::getPumpingStationCode() const {
    return pumping_station_code_;
}
