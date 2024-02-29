#include "../includes/Pipes.h"
using namespace std;

Pipes::Pipes(std::string serv_site_a, std::string serv_site_b, int capacity, bool direction) {
    this->serv_point_a_ = serv_site_a;
    this->serv_point_b_ = serv_site_b;
    this->capacity_ = capacity;
    this->direction_ = direction;
}

const string Pipes::getCitySourceName() const {
    return serv_point_a_;
}

const string Pipes::getCitySinkName() const {
    return serv_point_b_;
}

const int Pipes::getCapacity() const {
    return capacity_;
}

const bool Pipes::getDirection() const {
    return direction_;
}

