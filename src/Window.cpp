#include "../includes/Window.h"
#include <iostream>
using namespace std;

template<class T>
Window<T>::Window() {
    data_ = Data<T>();
}
template<class T>
void Window<T>::launch(){
    for(auto vertex : data_.getNetwork().getVertexSet()){
        cout << vertex;
    }
}