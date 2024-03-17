#ifndef PROJETO1DA_WINDOW_H
#define PROJETO1DA_WINDOW_H


#include "Data.h"

class Window{
public:
    Window();
    void launch();
    int displayMaxWater(std::string city);
    int displayAllCitiesMaxWater();
    void displayWaterNeeds();
private:
    Data data_;


};

#endif //PROJETO1DA_WINDOW_H
