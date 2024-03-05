#ifndef PROJETO1DA_PUMPINGSTATIONS_H
#define PROJETO1DA_PUMPINGSTATIONS_H

#include <string>


class PumpingStations{
    public:
        PumpingStations()=default;
        PumpingStations(int id, std::string pumping_station_code);
        int getId() const;
        const bool isVisited() const;
        const bool isProcessing() const;
        const int getIndegree() const;
        const std::string getPumpingStationCode() const;
    private:
        int id_;
        bool visited_;
        bool processing_;
        int indegree_;
        std::string pumping_station_code_;
};





#endif