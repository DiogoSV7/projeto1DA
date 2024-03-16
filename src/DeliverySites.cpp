#include "../includes/DeliverySites.h"

DeliverySites::DeliverySites(std::string city_name, int id, std::string code, double demand, std::string population)
        : city_name_(std::move(city_name)), id_(id), code_(std::move(code)), demand_(demand), population_(std::move(population)) {}

const std::string DeliverySites::getCityName() const {
    return city_name_;
}

const std::string DeliverySites::getCode() const {
    return code_;
}

const int DeliverySites::getId() const {
    return id_;
}

const double DeliverySites::getDemand() const {
    return demand_;
}

const std::string DeliverySites::getPopulation() const {
    return population_;
}

bool DeliverySites::operator==(const DeliverySites& other) const {
    return id_ == other.id_ && city_name_ == other.city_name_ && code_ == other.code_ && demand_ == other.demand_ && population_ == other.population_;
}

bool DeliverySites::operator!=(const DeliverySites& other) const {
    return !(*this == other);
}
