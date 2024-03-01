#include "../includes/Window.h"
#include <iostream>
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto vertex: data_.getNetwork().reservoirs_){
        cout << vertex.second.getId() << endl;
        cout << vertex.second.getCode() << endl;
    }
}