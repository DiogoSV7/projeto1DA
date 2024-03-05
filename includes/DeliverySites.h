
#ifndef PROJETO1DA_FILECITIES_H
#define PROJETO1DA_FILECITIES_H

#include <string>


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
        const bool isVisited() const;
        const bool isProcessing() const;
        const int getIndegree() const;
    private:
        std::string city_name_;
        std::string code_;
        int id_;
        int demand_;
        std::string population_;
        int indegree_;
        bool visited_;
        bool processing_;
};

#endif //PROJETO1DA_FILECITIES_H
