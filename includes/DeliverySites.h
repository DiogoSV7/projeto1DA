
#ifndef PROJETO1DA_FILECITIES_H
#define PROJETO1DA_FILECITIES_H

#include <string>
#include "Graph.h"

class DeliverySites{
    public:
        DeliverySites()=default;
        DeliverySites(std::string city_name, int id, std::string code, double demand, std::string population);
        const std::string getCityName() const;
        const std::string getCode() const;
        const int getId() const;
        const double getDemand() const;
        const std::string getPopulation() const;
        bool operator==(const DeliverySites& other) const;
    private:
        std::string city_name_;
        std::string code_;
        int id_;
        int demand_;
        std::string population_;
};

#endif //PROJETO1DA_FILECITIES_H
