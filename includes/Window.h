#ifndef PROJETO1DA_WINDOW_H
#define PROJETO1DA_WINDOW_H


#include "Data.h"

template<class T>
class Window{
public:
    Window();
    void launch();
private:
    Data<T> data_;

};

#endif //PROJETO1DA_WINDOW_H
