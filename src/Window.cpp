#include "../includes/Window.h"
#include <iostream>
#include <fstream>

using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    auto max_water_map = data_.maxWaterCity("C_2");
    cout << "Max water map size: " << max_water_map.size() << endl;
    displayMaxWater(max_water_map);
}

void Window::displayMaxWater(const std::unordered_map<std::string, double>& max_water_map) {
    std::ofstream outputFile("../saveddata/max_water_output.txt");
    if (outputFile.is_open()) {
        for (const auto& pair : max_water_map) {
            std::cout << pair.first << ": " << pair.second << std::endl;
            outputFile << pair.first << ": " << pair.second << std::endl;
        }
        outputFile.close();
        std::cout << "Output file created successfully!" << std::endl;
    } else {
        std::cerr << "Error: Unable to open output file!" << std::endl;
    }
}



