#include "../includes/Window.h"
#include <iostream>
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto vertex : data_.getNetwork().getVertexSet()) {

            cout << vertex->getInfo() << " "<<vertex->getAdj().size() <<endl;
    }
}