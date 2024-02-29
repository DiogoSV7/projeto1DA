#ifndef DA_PROJ_WATERRESERVOIR_H
#define DA_PROJ_WATERRESERVOIR_H

#include <string>

class WaterReservoir{
    public:
        WaterReservoir(std::string water_reservoir_name, std::string municipality, int id, int code, int max_delivery);
        const std::string getWaterReservoirName() const;
        const std::string getMunicipality() const;
        int getId() const;
        int getCode() const;
        int getMaxDelivery() const;
    private:
        std::string water_reservoir_name_;
        std::string municipality_;
        int id_;
        int code_;
        int max_delivery_;
};

#endif //DA_PROJ_WATERRESERVOIR_H
