#ifndef DA_PROJ_WATERRESERVOIR_H
#define DA_PROJ_WATERRESERVOIR_H

#include <string>

class WaterReservoir{
    public:
        WaterReservoir()=default;
        WaterReservoir(std::string water_reservoir_name, std::string municipality, int id, std::string code, int max_delivery);
        const std::string getWaterReservoirName() const;
        const std::string getMunicipality() const;
        const int getId() const;
        const std::string getCode() const;
        const int getMaxDelivery() const;

    private:
        std::string water_reservoir_name_;
        std::string municipality_;
        int id_;
        std::string code_;
        int max_delivery_;
};

#endif //DA_PROJ_WATERRESERVOIR_H
