#include "../includes/Window.h"
#include <iostream>
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto edge : data_.getNetwork().getPipes()){
        cout << edge.getCitySourceName() << endl;
        cout << edge.getCitySinkName() << endl;
        cout << edge.getDirection() << endl;
        cout << edge.getCapacity() << endl;
    }
}