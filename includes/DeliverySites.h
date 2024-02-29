
#ifndef PROJETO1DA_FILECITIES_H
#define PROJETO1DA_FILECITIES_H

#include <string>

class DeliverySites{
    public:
        DeliverySites(std::string city_name, int id, std::string code, int demand, int population);
        const std::string getCityName() const;
        const std::string getCode() const;
        const int getId() const;
        const int getDemand() const;
        const int getPopulation() const;
        bool operator==(const DeliverySites& other) const;
    private:
        std::string city_name_;
        std::string code_;
        int id_;
        int demand_;
        int population_;
};

struct DeliverySitesHash{
    int operator()(const DeliverySites& ds) const;

    bool operator()(const DeliverySites& ds1, const DeliverySites& ds2) const;
};

#endif //PROJETO1DA_FILECITIES_H
