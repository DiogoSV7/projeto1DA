#include "../includes/Window.h"
#include <iostream>
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto vertex : data_.getNetwork().getVertexSet()) {
        if(vertex->getType()==0){
            WaterReservoir water_reservoir = data_.findWaterReservoir(vertex->getInfo());
            cout << water_reservoir.getCode() << " " << water_reservoir.getMunicipality() << endl;
        }
    }
}