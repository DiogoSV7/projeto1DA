#include "../includes/Window.h"
#include <iostream>
#include <fstream>

using namespace std;

Window::Window() {
    data_ = Data();
}

void Window::launch(){
    //auto max_water_map = data_.maxWaterCity("C_9");
    //displayMaxWater(max_water_map);
    //auto water_needs_vector = data_.checkWaterNeeds();
    //displayWaterNeeds(water_needs_vector);
}

int Window::displayMaxWater(string city) {
    const std::unordered_map<string, double>& max_water_map = data_.maxWaterCity(city);
    std::ofstream outputFile("../saveddata/max_water_output.txt");
    if (outputFile.is_open()) {
        auto it = max_water_map.find("SuperSource");
        if (it != max_water_map.end() ) {
            std::cout << city << ": " << it->second << std::endl;
            outputFile << city << ": " << it->second << std::endl;
        } else {
            std::cerr << "Error: No data found for SuperSource in max_water_map!" << std::endl;
            return 1;
        }
        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open output file!" << std::endl;
        return 1;
    }
    return 0;
}
int Window::displayAllCitiesMaxWater() {
    const std::unordered_set<DeliverySites>& cities = data_.getDeliverySites();
    for (const auto& city : cities) {
        if(city.getCityName()=="SuperSource" || city.getCityName()=="SuperSink"){
            continue;
        }
        if(displayMaxWater(city.getCode())!=0){
            return 1;
        }
    }
    return 0;
}


void Window::displayWaterNeeds(){
    const vector<pair<string, double>>& water_needs_vector = data_.checkWaterNeeds();
    if (water_needs_vector.empty()) {
        std::cout << "All delivery sites are adequately supplied. No deficits found." << std::endl;
        return;
    }

    std::cout << "Delivery sites with deficits:" << std::endl;
    for (const auto& pair : water_needs_vector) {
        std::cout << "Delivery Site code: " << pair.first << ", Deficit: " << pair.second << std::endl;
    }
}

