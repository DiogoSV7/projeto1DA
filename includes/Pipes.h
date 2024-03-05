#ifndef PROJETO1DA_PIPES_H
#define PROJETO1DA_PIPES_H

#include <string>

class Pipes{
    public:
        Pipes()=default;
        Pipes(std::string serv_point_a, std::string serv_point_b, int capacity, int direction);
        const std::string getCitySourceName() const;
        const std::string getCitySinkName() const;
        const int getCapacity() const;
        const int getDirection() const; //1-> unidirectional 0-> bidirectional
    private:
        std::string serv_point_a_;
        std::string serv_point_b_;
        int capacity_;
        int direction_;
};


#endif //PROJETO1DA_PIPES_H
