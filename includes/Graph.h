#ifndef PROJETO1DA_GRAPH_H
#define PROJETO1DA_GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "PumpingStations.h"
#include "DeliverySites.h"
#include "Pipes.h"
#include "WaterReservoir.h"

class WaterReservoir;
class PumpingStations;
class DeliverySites;

class Graph {
public:
    Graph()=default;
    
    void addPumpingStation(const std::string& code, const PumpingStations& ps) {
        pumpingStations_.emplace(code, ps);
    }

    void addDeliverySite(const std::string& code, const DeliverySites& ds) {
        deliverySites_.emplace(code, ds);
    }

    void addWaterReservoir(const std::string& code, const WaterReservoir& wr){
        reservoirs_.emplace(code,wr);
    }

    void addEdge(const Pipes& pipe){
        pipes_.push_back(pipe);
    }

    std::unordered_map<std::string, WaterReservoir> getReservoirs() const {
        return reservoirs_;
    }
    std::unordered_map<std::string, PumpingStations> getPumpingStations() const {
        return pumpingStations_;
    }
    std::unordered_map<std::string, DeliverySites> getDeliverySites() const {
        return deliverySites_;
    }
    std::vector<Pipes> getPipes() const {
        return pipes_;
    }
private:
    std::unordered_map<std::string, WaterReservoir> reservoirs_;
    std::unordered_map<std::string, PumpingStations> pumpingStations_;
    std::unordered_map<std::string, DeliverySites> deliverySites_;
    std::vector<Pipes> pipes_;
};

#endif



