#include "../includes/Pipes.h"
using namespace std;

Pipes::Pipes(std::string serv_site_a, std::string serv_site_b, int capacity, int direction) {
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

const int Pipes::getDirection() const {
    return direction_;
}

bool Pipes::operator==(const Pipes& other) const {
    return (serv_point_a_ == other.serv_point_a_) &&
           (serv_point_b_ == other.serv_point_b_) &&
           (capacity_ == other.capacity_) &&
           (direction_ == other.direction_);
}

bool Pipes::operator!=(const Pipes& other) const {
    return !(*this == other);
}