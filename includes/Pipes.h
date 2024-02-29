#ifndef PROJETO1DA_PIPES_H
#define PROJETO1DA_PIPES_H

#include <string>

class Pipes{
    public:
        Pipes(std::string city_source_name, std::string city_sink_name, int capacity, bool direction);
        const std::string getCitySourceName() const;
        const std::string getCitySinkName() const;
        const int getCapacity() const;
        const bool getDirection() const; //true-> unidirectional false-> bidirectional
        bool operator==(const Pipes& other) const;
    private:
        std::string city_source_name_;
        std::string city_sink_name_;
        int capacity_;
        bool direction_;
};

struct PipesHash{
    int operator()(const Pipes& pipe) const;
    bool operator()(const Pipes& pipe1, const Pipes& pipe2) const;
};

#endif //PROJETO1DA_PIPES_H
