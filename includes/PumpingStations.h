#ifndef PROJETO1DA_PUMPINGSTATIONS_H
#define PROJETO1DA_PUMPINGSTATIONS_H

#include <string>

class PumpingStations{
    public:
        PumpingStations(int id, std::string pumping_station_code);
        int getId() const;
        const std::string getPumpingStationCode() const;
        bool operator==(const PumpingStations& other) const;
    private:
        int id_;
        std::string pumping_station_code_;
};

struct PumpingStationsHash{
    int operator()(const PumpingStations& wr) const;

    bool operator()(const PumpingStations& wr1, const PumpingStations& wr2) const;
};




#endif