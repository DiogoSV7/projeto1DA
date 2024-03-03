#include "../includes/Window.h"
#include <iostream>
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto vertex: data_.getNetwork().getReservoirs()){
        cout << vertex.second.getId() << endl;
        cout << vertex.second.getCode() << endl;
    }
    for(auto vertex: data_.getNetwork().getPumpingStations()){
        cout << vertex.second.getId() << endl;
        cout << vertex.second.getPumpingStationCode() << endl;
    }
}