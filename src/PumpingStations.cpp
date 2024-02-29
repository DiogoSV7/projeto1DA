
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

bool PumpingStations::operator==(const PumpingStations &other) const {
    return this->getId() == other.getId();
}

int PumpingStationsHash::operator()(const PumpingStations &ps) const {
    return std::hash<int>()(ps.getId());
}

bool PumpingStationsHash::operator()(const PumpingStations &ps1, const PumpingStations &ps2) const {
    return ps1.getId() == ps2.getId();
}

