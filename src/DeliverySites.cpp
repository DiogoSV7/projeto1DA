#include "../includes/DeliverySites.h"
using namespace std;

DeliverySites::DeliverySites(std::string city_name, int id, std::string code, int demand, int population) {
    this->city_name_=city_name;
    this->id_ = id;
    this->code_ =code;
    this->demand_ =demand;
    this->population_ =population;
}

const string DeliverySites::getCityName() const {
    return city_name_;
}

const int DeliverySites::getId() const {
    return id_;
}

const string DeliverySites::getCode() const {
    return code_;
}

const int DeliverySites::getDemand() const {
    return demand_;
}

const int DeliverySites::getPopulation() const {
    return population_;
}

