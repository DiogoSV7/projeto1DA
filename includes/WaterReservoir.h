
#ifndef PROJETO1DA_WATERRESERVOIR_H
#define PROJETO1DA_WATERRESERVOIR_H

#include <string>


class WaterReservoir{
public:
    WaterReservoir(std::string water_reservoir_name, std::string municipality, int id, std::string code, int max_delivery);
    const std::string getWaterReservoirName() const;
    const std::string getMunicipality() const;
    const int getId() const;
    const std::string getCode() const;
    const int getMaxDelivery() const;
    bool operator==(const WaterReservoir& other) const;
    bool operator!=(const WaterReservoir& other) const;

private:
    std::string water_reservoir_name_;
    std::string municipality_;
    int id_;
    std::string code_;
    int max_delivery_;
};

namespace std {
    template <>
    struct hash<WaterReservoir> {
        size_t operator()(const WaterReservoir& reservoir) const {
            size_t hashName = hash<std::string>{}(reservoir.getWaterReservoirName());
            size_t hashMunicipality = hash<std::string>{}(reservoir.getMunicipality());
            size_t hashId = hash<int>{}(reservoir.getId());
            size_t hashCode = hash<std::string>{}(reservoir.getCode());
            return hashName ^ (hashMunicipality << 1) ^ (hashId << 2) ^ (hashCode << 3);
        }
    };
}

#endif //PROJETO1DA_WATERRESERVOIR_H
