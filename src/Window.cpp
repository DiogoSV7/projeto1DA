#include "../includes/Window.h"
#include <iostream>
#include <fstream>

using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    auto max_water_map = data_.maxWaterCity("C_9");
    displayMaxWater(max_water_map);
    auto water_needs_vector = data_.checkWaterNeeds();
    displayWaterNeeds(water_needs_vector);
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

void Window::displayWaterNeeds(const std::vector<std::pair<std::string, double>>& water_needs_vector){
    if (water_needs_vector.empty()) {
        std::cout << "All delivery sites are adequately supplied. No deficits found." << std::endl;
        return;
    }

    std::cout << "Delivery sites with deficits:" << std::endl;
    for (const auto& pair : water_needs_vector) {
        std::cout << "Delivery Site code: " << pair.first << ", Deficit: " << pair.second << std::endl;
    }
}

