#ifndef PROJETO1DA_WINDOW_H
#define PROJETO1DA_WINDOW_H


#include "Data.h"

class Window{
public:
    Window();
    void launch();
    void displayMaxWater(const std::unordered_map<std::string, double>& max_water_map);
    void displayWaterNeeds(const std::vector<std::pair<std::string, double>>& water_needs_vector);
private:
    Data data_;

};

#endif //PROJETO1DA_WINDOW_H
