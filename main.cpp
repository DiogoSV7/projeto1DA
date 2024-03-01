#include <iostream>
#include "includes/Window.h"

int main() {
    try{
        Window().launch();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what();
        return 1;
    }
    return 0;
}
