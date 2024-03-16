#ifndef PROJETO1DA_DATA_H
#define PROJETO1DA_DATA_H

#include <unordered_set>
#include <string>
#include <vector>
#include "WaterReservoir.h"
#include "DeliverySites.h"
#include "PumpingStations.h"
#include "Graph.h"

class Data {
    public:
        Data();
        void readDeliverySites();
        void readPipes();
        void readPumpingStations();
        void readWaterReservoir();
        WaterReservoir findWaterReservoir(const std::string code) const;
        PumpingStations findPumpingStation(const std::string code) const;
        DeliverySites findDeliverySite(const std::string code) const;
        std::vector<WaterReservoir> getWaterReservoirs() const;
        std::vector<PumpingStations> getPumpingStations() const;
        std::vector<DeliverySites> getDeliverySites() const;
        Graph getNetwork();
        int maxWaterCity(const std::string& city_code);
    private:
        Graph network_;
        std::vector<WaterReservoir> water_reservoirs_;
        std::vector<PumpingStations> pumping_stations_;
        std::vector<DeliverySites> delivery_sites_;

};


#endif //PROJETO1DA_DATA_H
