#ifndef PROJETO1DA_PIPES_H
#define PROJETO1DA_PIPES_H

#include <string>

class Pipes{
    public:
        Pipes(std::string city_source_name, std::string city_sink_name, int capacity, bool direction);
        const std::string getCitySourceName() const;
        const std::string getCitySinkName() const;
        int getCapacity() const;
        bool getDirection() const; //true-> unidirectional false-> bidirectional

    private:
        std::string city_source_name_;
        std::string city_sink_name_;
        int capacity_;
        bool direction_;
};

#endif //PROJETO1DA_PIPES_H
