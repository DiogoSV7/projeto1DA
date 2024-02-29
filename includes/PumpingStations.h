#ifndef PROJETO1DA_PUMPINGSTATIONS_H
#define PROJETO1DA_PUMPINGSTATIONS_H

#include <string>

class PumpingStations{
    public:
        PumpingStations(int id, std::string pumping_station_code);
        int getId() const;
        const std::string getPumpingStationCode() const;
    private:
        int id_;
        std::string pumping_station_code_;
};



#endif