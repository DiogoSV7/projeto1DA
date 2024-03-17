//
// Created by tiago on 17-03-2024.
//

#ifndef PROJETO1DA_MENU_H
#define PROJETO1DA_MENU_H




#include "Window.h"


class Menu {
public:
    Menu();
    void showMenu();
    static void drawTop();
    static void drawBottom();
private:
    Window window_;
};




#endif //PROJETO1DA_MENU_H
