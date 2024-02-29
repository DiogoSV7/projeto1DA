#ifndef DA_PROJ_WATERRESERVOIR_H
#define DA_PROJ_WATERRESERVOIR_H

#include <string>

class WaterReservoir{
    public:
        WaterReservoir(std::string water_reservoir_name, std::string municipality, int id, int code, int max_delivery);
        const std::string getWaterReservoirName() const;
        const std::string getMunicipality() const;
        const int getId() const;
        const int getCode() const;
        const int getMaxDelivery() const;
        bool operator==(const WaterReservoir& other) const;

    private:
        std::string water_reservoir_name_;
        std::string municipality_;
        int id_;
        int code_;
        int max_delivery_;
};

struct WaterReservoirHash{
    int operator()(const WaterReservoir& wr) const;

    bool operator()(const WaterReservoir& wr1, const WaterReservoir& wr2) const;
};
#endif //DA_PROJ_WATERRESERVOIR_H
