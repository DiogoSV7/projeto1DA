
#ifndef PROJETO1DA_FILECITIES_H
#define PROJETO1DA_FILECITIES_H

#include <string>

class DeliverySites{
    public:
        DeliverySites(std::string city_name, int id, std::string code, int demand, int population);
        const std::string getCityName() const;
        const std::string getCode() const;
        int getId() const;
        int getDemand() const;
        int getPopulation() const;
    private:
        std::string city_name_;
        std::string code_;
        int id_;
        int demand_;
        int population_;
};

#endif //PROJETO1DA_FILECITIES_H
