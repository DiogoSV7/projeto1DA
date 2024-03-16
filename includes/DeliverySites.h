
#ifndef PROJETO1DA_FILECITIES_H
#define PROJETO1DA_FILECITIES_H

#include <string>

class DeliverySites {
public:
    DeliverySites() = default;
    DeliverySites(std::string city_name, int id, std::string code, double demand, std::string population);
    const std::string getCityName() const;
    const std::string getCode() const;
    const int getId() const;
    const double getDemand() const;
    const std::string getPopulation() const;
    bool operator==(const DeliverySites& other) const;
    bool operator!=(const DeliverySites& other) const;

private:
    std::string city_name_;
    std::string code_;
    int id_;
    int demand_;
    std::string population_;
};

namespace std {
    template <>
    struct hash<DeliverySites> {
        size_t operator()(const DeliverySites& site) const {
            size_t hashCity = hash<std::string>{}(site.getCityName());
            size_t hashCode = hash<std::string>{}(site.getCode());
            size_t hashId = hash<int>{}(site.getId());
            return hashCity ^ (hashCode << 1) ^ (hashId << 2);
        }
    };
}

#endif//PROJETO1DA_FILECITIES_H
