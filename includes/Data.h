#ifndef PROJETO1DA_DATA_H
#define PROJETO1DA_DATA_H

#include <unordered_set>
#include <string>
#include <vector>
#include "WaterReservoir.h"
#include "DeliverySites.h"
#include "PumpingStations.h"
#include "Pipes.h"
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
        std::unordered_set<WaterReservoir> getWaterReservoirs() const;
        std::unordered_set<PumpingStations> getPumpingStations() const;
        std::unordered_set<DeliverySites> getDeliverySites() const;
        Graph getNetwork();
        std::unordered_map<std::string, double> maxWaterCity(const std::string& city_name);
        void testAndVisit(std::queue<Vertex*>& q, Edge* e, Vertex* w, double residual);
        bool findAugmentingPath(Vertex* s, Vertex* t);
        double findMinResidualAlongPath(Vertex* s, Vertex* t);
        void augmentFlowAlongPath(Vertex* s, Vertex* t, double f);
        void edmondsKarp(std::string source, std::string target);
        Pipes findPipes(const std::string serv_point_a, const std::string serv_point_b) const;
        void addSuperSourceAndSink(const std::string& superSourceName, const std::string& superSinkName);
    private:
        Graph network_;
        std::unordered_set<Pipes> pipes_;
        std::unordered_set<WaterReservoir> water_reservoirs_;
        std::unordered_set<PumpingStations> pumping_stations_;
        std::unordered_set<DeliverySites> delivery_sites_;

};


#endif //PROJETO1DA_DATA_H
