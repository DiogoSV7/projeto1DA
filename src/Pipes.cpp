#include "../includes/Pipes.h"
using namespace std;

Pipes::Pipes(std::string city_source_name, std::string city_sink_name, int capacity, bool direction) {
    this->city_source_name_ = city_source_name;
    this->city_sink_name_ = city_sink_name;
    this->capacity_ = capacity;
    this->direction_ = direction;
}

const string Pipes::getCitySourceName() const {
    return city_source_name_;
}

const string Pipes::getCitySinkName() const {
    return city_sink_name_;
}

const int Pipes::getCapacity() const {
    return capacity_;
}

const bool Pipes::getDirection() const {
    return direction_;
}

bool Pipes::operator==(const Pipes &other) const {
    return this->getCitySourceName() == other.getCitySourceName() && this->getCitySinkName() == other.getCitySinkName();
}

int PipesHash::operator()(const Pipes& pipe) const {
    size_t hash1 = std::hash<std::string>()(pipe.getCitySourceName());
    size_t hash2 = std::hash<std::string>()(pipe.getCitySinkName());
    return hash1 ^ (hash2 << 1);
}

bool PipesHash::operator()(const Pipes& pipe1, const Pipes& pipe2) const {
    return pipe1.getCitySourceName() == pipe2.getCitySourceName() &&
           pipe1.getCitySinkName() == pipe2.getCitySinkName() &&
           pipe1.getCapacity() == pipe2.getCapacity() &&
           pipe1.getDirection() == pipe2.getDirection();
}