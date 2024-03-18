#include "../includes/Menu.h"
#include "../includes/Data.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


/**
 * @brief Default constructor for the Menu class.
 *
 * @detail This constructor initializes an instance of the Menu class.
 *
 * Time Complexity: O(1)
 */
Menu::Menu() {
    data_ = Data();
}

/**
 * @brief Draws the top section of the menu interface.
 *
 * @detail This function is responsible for rendering the top section of the menu interface.
 *
 * Time Complexity: O(1)
 */
void Menu::drawTop(){
    cout << "┌──────────────────────────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    cout << setw(50) << "│        █████    █████  ███    ███ ███████        │" << endl;
    cout << setw(50) << "│        ██   ██ ██   ██ ████  ████ ██             │" << endl;
    cout << setw(50) << "│        ██   ██ ███████ ██ ████ ██ ███████        │" << endl;
    cout << setw(50) << "│        ██   ██ ██   ██ ██  ██  ██      ██        │" << endl;
    cout << setw(50) << "│        ██████  ██   ██ ██      ██ ███████        │" << endl;
    cout << "│" << setw(53) << "│" << endl;
}

/**
 * @brief Draws the bottom section of the menu interface.
 *
 * @detail This function is responsible for rendering the bottom section of the menu interface.
 *
 * Time Complexity: O(1)
 */
void Menu::drawBottom(){
    cout << "└──────────────────────────────────────────────────┘" << endl;
}

/**
 * @brief Display the main menu and handle user interactions.
 *
 * @info This method initializes a FlightManagementSystem and Data objects, then displays a menu with different options.
 * The user can choose options related to airports, statistics, or finding the best flight options.
 *
 * @complexity Time complexity: depends on the option chosen by the user.
 */
void Menu::showMenu() {
    char key;
    bool flag = true;
    while (flag) {
        drawTop();
        cout << "│" << setw(53) << "│" << endl;
        cout << "│    Options:                                      │" << endl;
        cout << "│     [1] Display                                  │" << endl;
        cout << "│     [2] Cities in Lack of Water                  │" << endl;
        cout << "│     [3] Maximum Flow to Cities                   │" << endl;
        cout << "│     [4]                                          │" << endl;
        cout << "│     [5] Remove / Restore                         │" << endl;
        cout << "│     [Q] Exit                                     │" << endl;
        cout << "│" << setw(53) << "│" << endl;
        drawBottom();
        cout << "Choose an option: ";
        cin >> key;
        switch (key) {
            case '1': {
                displayDisplayMenu();
                break;
            }
            case '2': {
                displayWaterNeeds();
                break;
            }
            case '3': {
                char key1;
                drawTop();
                cout << "│    Options:                                      │" << endl;
                cout << "│     [1] Choose All Cities                        │" << endl;
                cout << "│     [2] Choose Specific City (C_1 to C_9)        │" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key1;
                switch (key1) {
                    case '1': {
                        //percorrer lista de cidades e fazer a função displayMaxWater para cada uma
                        if(displayAllCitiesMaxWater()==0){
                        }
                        break;
                    }
                    case '2': {
                        string city;
                        cout << "Choose a city (C_1 to C_9): ";
                        cin >> city;
                        if(displayMaxWater(city)==0){
                        }
                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }

                };
                break;
            }
            case '5': {
                char key2;
                cout << "┌── Remove / Restore Menu ─────────────────────────┐" << endl;
                cout << "│" << setw(53) << "│" << endl;
                cout << "│    Options:                                      │" << endl;
                cout << "│     [1] Remove Water Reservoir                   │" << endl;
                cout << "│     [2] Remove Pumping Station                   │" << endl;
                cout << "│     [3] Remove Delivery Site                     │" << endl;
                cout << "│     [4] Remove Pipe                              │" << endl;
                cout << "│     [5] Restore Graph                            │" << endl;
                cout << "│" << setw(53) << "│" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key2;
                switch (key2) {
                    case '1': {
                        string water_res_code;
                        cout << "Insert the Water Reservoir code:";
                        cin >> water_res_code;
                        data_.removeWaterReservoir(water_res_code);
                        break;
                    }
                    case '2': {
                        string pumping_station_code;
                        cout << "Insert the Pumping Station code:";
                        cin >> pumping_station_code;
                        data_.removePumpingStations(pumping_station_code);
                        break;
                    }
                    case '3': {
                        string delivery_site_code;
                        cout << "Insert the Delivery Site code:";
                        cin >> delivery_site_code;
                        data_.removeDeliverySite(delivery_site_code);
                        break;
                    }
                    case '4': {
                        string serv_site_a, serv_site_b;
                        cout << "Insert the Service Site A code:";
                        cin >> serv_site_a;
                        cout << "Insert the Service Site B code:";
                        cin >> serv_site_b;
                        data_.removePipe(serv_site_a,serv_site_b);
                        break;
                    }
                    case '5': {
                        data_.restoreGraph();
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                break;
            }
            case 'Q' : {
                flag = false;
                break;
            }
            default: {
                cout << endl << "Invalid option!" << endl;
            }

        };
        cout << endl;
        cout << "Would you like to do something else? (Y/N) \n";
        char newCicle;
        cin >> newCicle;
        if (newCicle == 'N') flag = false;
        while (newCicle != 'Y') {
            if (newCicle == 'N') {
                flag = false;
                break;
            }
            cout << R"(Please type "Y" or "N".)" << endl;
            cin >> newCicle;
        }
    }
}

int Menu::displayMaxWater(std::string city){
    const std::unordered_map<std::string, double>& max_water_map = data_.maxWaterCity(city);
    std::ofstream outputFile("../saveddata/max_water_output.txt", std::ios::app); // Open in append mode

    if (outputFile.is_open()) {
        auto it = max_water_map.find("SuperSource");
        if (it != max_water_map.end()) {
            std::cout << "│" <<  std::setw(7) << city << " : " << left << setw(40) << it->second << right <<  "│" << std::endl;
            outputFile << "│" << std::setw(7) << city << " : " <<left << setw(40) << it->second << right << "│" << std::endl;
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


int Menu::extractNumberFromCode(const std::string& code) {
    return std::stoi(code.substr(2));
}

int Menu::displayAllCitiesMaxWater() {
    const std::unordered_set<DeliverySites>& cities = data_.getDeliverySites();

    std::vector<DeliverySites> sortedCities;
    for (const auto& city : cities) {
        if (city.getCityName() == "SuperSource" || city.getCityName() == "SuperSink") {
            continue;
        }
        sortedCities.push_back(city);
    }

    std::sort(sortedCities.begin(), sortedCities.end(), [this](const DeliverySites& a, const DeliverySites& b) {
        return extractNumberFromCode(a.getCode()) < extractNumberFromCode(b.getCode());
    });
    cout << "┌─ Maximum Amount of Water ────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for (const auto& city : sortedCities) {
        if (displayMaxWater(city.getCode()) != 0) {
            return 1;
        }
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
    return 0;
}


void Menu::displayWaterNeeds(){
    const vector<pair<string, double>>& water_needs_vector = data_.checkWaterNeeds();
    if (water_needs_vector.empty()) {
        std::cout << "All delivery sites are adequately supplied. No deficits found." << std::endl;
        return;
    }

    cout << "┌── Water Deficits ────────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for (const auto& pair : water_needs_vector) {
        std::cout << "│ " << left << setw(20) << "Delivery Site code: " << left << setw(10) << pair.first << left << setw(10) << "Deficit: " << left << setw(9) <<  pair.second  << right << "│" << std::endl;
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}

void Menu::displayDisplayMenu() const {
    char key;
    bool flag = true;
    while (flag) {
        cout << "┌── Display Menu ──────────────────────────────────┐" << endl;
        cout << "│" << setw(53) << "│" << endl;
        cout << "│    Options:                                      │" << endl;
        cout << "│     [1] Display Water Reservoirs                 │" << endl;
        cout << "│     [2] Display Pumping Stations                 │" << endl;
        cout << "│     [3] Display Delivery Sites                   │" << endl;
        cout << "│     [Q] Quit Display Menu                        │" << endl; 
        cout << "│" << setw(53) << "│" << endl;
        drawBottom();
        cout << "Choose an option: ";
        cin >> key;

        switch (key) {
            case '1': {
                displayAllWaterReservoirs();
                break;
            }
            case '2': {
                displayAllPumpingStations();
                break;
            }
            case '3': {
                displayAllDeliverySites();
                break;
            }
            case 'Q': {
                flag = false;
                break;
            }
            default: {
                cout << endl << "Invalid option!" << endl;
            }
        };
        cout << endl;
        cout << "Press any key: \n";
        char newCicle;
        cin >> newCicle;
        break;
    }
}


void Menu::displayAllWaterReservoirs() const{
    std::unordered_set<WaterReservoir> reservoirs;
    for (auto water_res : data_.getNetwork().getVertexSet()) {
        if (water_res->getType() == 0) {
            reservoirs.insert(data_.findWaterReservoir(water_res->getInfo()));
        }
    }
    cout << "┌─ Water Reservoirs ───────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for(auto water_res: reservoirs){
        if(water_res.getCode()=="SuperSource"){
            continue;
        }
        cout << "│ " << left << setw(6) << "Name: " << right << left << setw(29) << water_res.getWaterReservoirName() << right << setw(6) << "Code: " << right << left << setw(8) << water_res.getCode() << right << "│" << endl;
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}

void Menu::displayAllPumpingStations() const{
    std::unordered_set<PumpingStations> pumping_stations;
    for(auto pump_sta : data_.getNetwork().getVertexSet()){
        if(pump_sta->getType()==1){
            pumping_stations.insert(data_.findPumpingStation(pump_sta->getInfo()));
        }
    }
    cout << "┌─ Pumping Stations ───────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for(auto pump_sta: pumping_stations){
        cout << "│ " << left << setw(6) << "Code: "<< right << left << setw(43) << pump_sta.getPumpingStationCode() << right << "│" << endl;
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}

void Menu::displayAllDeliverySites() const{
    std::unordered_set<DeliverySites> delivery_sites;
    for(auto del_sites : data_.getNetwork().getVertexSet()){
        if(del_sites->getType()==2){
            delivery_sites.insert(data_.findDeliverySite(del_sites->getInfo()));
        }
    }
    cout << "┌─ Delivery Sites ─────────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for(auto del_site : delivery_sites){
        if(del_site.getCode()=="SuperSink"){
            continue;
        }
        cout << "│ " << left << setw(6) << "Name: " << right << left << setw(29) << del_site.getCityName() << right << setw(6) << "Code: " << right << left << setw(8) << del_site.getCode() << right << "│" << endl;
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}