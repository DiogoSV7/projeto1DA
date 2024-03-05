#include "../includes/DeliverySites.h"
using namespace std;

DeliverySites::DeliverySites(std::string city_name, int id, std::string code, double demand, string population) {
    this->city_name_=city_name;
    this->id_ = id;
    this->code_ =code;
    this->demand_ =demand;
    this->population_ =population;
    this->visited_=false;
    this->processing_=false;
    this->indegree_=0;
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

const double DeliverySites::getDemand() const {
    return demand_;
}

const string DeliverySites::getPopulation() const {
    return population_;
}

const bool DeliverySites::isVisited() const {
    return visited_;
}

const bool DeliverySites::isProcessing() const {
    return processing_;
}

const int DeliverySites::getIndegree() const {
    return indegree_;
}
