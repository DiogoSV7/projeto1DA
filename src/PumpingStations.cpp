#include "../includes/PumpingStations.h"

PumpingStations::PumpingStations(int id, std::string pumping_station_code)
        : id_(id), pumping_station_code_(std::move(pumping_station_code)) {}

int PumpingStations::getId() const {
    return id_;
}

const std::string PumpingStations::getPumpingStationCode() const {
    return pumping_station_code_;
}

bool PumpingStations::operator==(const PumpingStations& other) const {
    return id_ == other.id_ && pumping_station_code_ == other.pumping_station_code_;
}

bool PumpingStations::operator!=(const PumpingStations& other) const {
    return !(*this == other);
}
