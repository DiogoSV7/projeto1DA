#include "../includes/Window.h"
using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    for(auto vertex: data_.getNetwork().getVertices()){
        cout << vertex.second->getCode() << "/n";
    }
}