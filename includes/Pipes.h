#ifndef PROJETO1DA_PIPES_H
#define PROJETO1DA_PIPES_H

#include <string>

class Pipes{
    public:
        Pipes()=default;
        Pipes(std::string serv_point_a, std::string serv_point_b, int capacity, bool direction);
        const std::string getCitySourceName() const;
        const std::string getCitySinkName() const;
        const int getCapacity() const;
        const bool getDirection() const; //true-> unidirectional false-> bidirectional
    private:
        std::string serv_point_a_;
        std::string serv_point_b_;
        int capacity_;
        bool direction_;
};


#endif //PROJETO1DA_PIPES_H
