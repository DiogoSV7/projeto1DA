#ifndef PROJETO1DA_DATA_H
#define PROJETO1DA_DATA_H

#include <unordered_set>
#include "WaterReservoir.h"
#include "PumpingStations.h"
#include "Pipes.h"
#include "DeliverySites.h"
#include "Graph.h"

typedef std::unordered_set<DeliverySites, DeliverySitesHash> DeliverySitesSet;

typedef std::unordered_set<PumpingStations, PumpingStationsHash> PumpingStationsSet;

typedef std::unordered_set<Pipes,PipesHash> PipesSet;

typedef std::unordered_set<WaterReservoir, WaterReservoirHash> WaterReservoirSet;

class Data {
    public:
        Data();
        void readDeliverySites();
        void readPipes();
        void readPumpingStations();
        void readWaterReservoir();
        const std::unordered_set<WaterReservoir> getWaterReservoirs() const;
        const std::unordered_set<PumpingStations> getPumpingStations() const;
        const std::unordered_set<Pipes> getPipes() const;
        const std::unordered_set<DeliverySites> getDeliverySites() const;
    private:
        WaterReservoirSet water_reservoirs_set_;
        PumpingStationsSet pumping_stations_set_;
        PipesSet pipes_set_;
        DeliverySitesSet delivery_sites_set_;
};


#endif //PROJETO1DA_DATA_H
