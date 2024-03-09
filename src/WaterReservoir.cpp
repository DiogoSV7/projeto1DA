#include <string>
#include "../includes/WaterReservoir.h"
using namespace std;

WaterReservoir::WaterReservoir(string water_reservoir_name, string municipality, int id, string code, int max_delivery){
    this->water_reservoir_name_=water_reservoir_name;
    this->municipality_=municipality;
    this->code_=code;
    this->id_=id;
    this->max_delivery_=max_delivery;
}

const string WaterReservoir::getWaterReservoirName() const {
    return water_reservoir_name_;
}

const string WaterReservoir::getMunicipality() const {
    return municipality_;
}

const string WaterReservoir::getCode() const {
    return code_;
}

const int WaterReservoir::getId() const {
    return id_;
}

const int WaterReservoir::getMaxDelivery() const {
    return max_delivery_;
}
