#include "../includes/Menu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <locale>
using namespace std;
/**
 * @brief Constructor for the Menu class.
 *
 * @detail This constructor initializes an instance of the Menu class, and runs edmondsKarp function to populate the flow of the graph with the large dataset.
 *
 * @complexity Time Complexity:: O(V E^2) where V are all the vertices of the graph and E all the pipes in the graph.
 */
Menu::Menu(bool useLargeDataset) {
    data_ = Data(useLargeDataset);

}

/**
 * @brief Draws the top section of the menu interface.
 *
 * @detail This function is responsible for rendering the top section of the menu interface.
 *
 * @complexity Time Complexity:: O(1)
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
 * @complexity Time Complexity: O(1)
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
 * @complexity Time Complexity: depends on the option chosen by the user.
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
        cout << "│     [4] Remove / Restore                         │" << endl;
        cout << "│     [5] Display Pipes Statistics                 │" << endl;
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
                cout << "┌── Maximum Flow to Cities─────────────────────────┐" << endl;
                cout << "│" << setw(53) << "│" << endl;
                cout << "│    Options:                                      │" << endl;
                cout << "│     [1] Choose All Cities                        │" << endl;
                cout << "│     [2] Choose Specific City by Code             │" << endl;
                cout << "│" << setw(53) << "│" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key1;
                switch (key1) {
                    case '1': {
                        vector<string> v;
                        //percorrer lista de cidades e fazer a função displayMaxWater para cada uma
                        for(DeliverySites city: data_.getDeliverySites()){
                            v.push_back(city.getCode());
                        }
                        if(displayMaxWater(v)==0){
                        }
                        break;
                    }
                    case '2': {
                        string city;
                        cout << "Choose a city (C_1 to C_9): ";
                        cin >> city;
                        auto vertex = data_.getNetwork().findVertex(city);
                        if (vertex == NULL) {
                            cout << "Wrong City Code"<< endl;
                            break;
                        }
                        vector<string> v(1,city);
                        if(displayMaxWater(v)==0){
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
            case '4': {
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
                        unordered_map<string, DeliverySites> temp= data_.removeWaterReservoir(water_res_code);
                        
                        compareWaterReservoirs(temp);
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
            case '5' : {
                double avgDiff = data_.computeAvgPipeDif();
                double varDiff = data_.computePipeDifVar();
                double maxDiff = data_.computePipeMaxDif();
                cout << "┌─ Pipes Statistics ───────────────────────────────┐" << endl;
                cout << "│" << setw(53) << "│" << endl;
                cout << "│ Average Difference: " << left << setw(29) << fixed << setprecision(2) << avgDiff << right << "│"  << endl;
                cout << "│ Variance of Differences: " << left << setw(24) << scientific << setprecision(2) << varDiff << right << "│" << endl;
                cout << "│ Maximum Difference: " << left << setw(29) << fixed << setprecision(2) << maxDiff << right << "│" << endl;
                cout << "│" << setw(53) << "│" << endl;
                drawBottom();
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

/**
 * @brief Extracts the numerical part from a city code.
 *
 * @param code The city code from which to extract the numerical part.
 * @return The numerical part of the city code.
 *
 * Time Complexity: O(1)
 */
int Menu::extractNumberFromCode(const std::string& code) {
    return std::stoi(code.substr(2));
}

/**
 * @brief Displays the maximum water flow to specified cities.
 *
 * @param cities A vector containing the codes of the cities to display the maximum water flow for.
 * @return 0 if the operation succeeds, 1 otherwise.
 *
 * @complexity Time Complexity:: O(d * p), where d is the number of cities and p is the maximum number of adjacent edges for a city.
 */
int Menu::displayMaxWater(vector<string> cities){
    std::ofstream outputFile("../saveddata/max_water_output.txt", std::ios::app); // Open in append mode
    auto network= data_.getNetwork();
    data_.edmondsKarp("SuperSource", "SuperSink");
    cities.erase(std::remove(cities.begin(), cities.end(), "SuperSink"), cities.end());
    double maxflow=0;
    cout<<"┌── Max Water Flow ────────────────────────────────┐"<<endl;
    cout << "│" << setw(53) << "│" << endl;

    std::sort(cities.begin(), cities.end(), [this](const std::string& a, const std::string& b) {
        return extractNumberFromCode(a) < extractNumberFromCode(b);
    });
    if (outputFile.is_open()) {
        for (auto adj: cities) {
            auto vertex = network.findVertex(adj);
            if (vertex == NULL) {
                cout << "Wrong City Code"<< endl;
                return 1;
            }

            float sum = 0;
            for (auto edge: vertex->getAdj()) {
                sum += edge->getFlow();
            }
            maxflow+=sum;
            std::cout << "│" << std::setw(7) << adj << " : " << left << setw(40) << sum << right << "│" << std::endl;
            outputFile << "│" << std::setw(7) << adj << " : " << left << setw(40) << sum << right << "│" << std::endl;
        }
        if(cities.size()+1==data_.getDeliverySites().size()) {
            cout << "│                                                  │" << endl;
            std::cout << "│" << std::setw(9) << "MaxFlow" << " : " << left << setw(38) << maxflow << right << "│"
                      << std::endl;
            outputFile << "│" << std::setw(9) << "MaxFlow" << " : " << left << setw(38) << maxflow << right << "│"
                       << std::endl;
        }
        outputFile.close();
    }else {
        std::cerr << "Error: Unable to open output file!" << std::endl;
        return 1;
    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
    return 0;
}

/**
 * @brief Displays delivery sites with water deficits.
 *
 * @complexity Time Complexity: O(n), where n is the number of delivery sites.
 */
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
/**
 * @brief Displays the menu for displaying various options.
 *
 * @complexity Time Complexity: depends on the option chosen by the user.
 */
void Menu::displayDisplayMenu() const {
    char key;

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

                break;
            }
            default: {
                cout << endl << "Invalid option!" << endl;
            }
        };


}

/**
 * @brief Counts the number of accented characters in a given string.
 *
 * @note This function counts the number of accented characters (including those with diacritics) in the input string. It considers accented characters commonly used in the Portuguese language.
 *
 * @param str The input string to count accented characters from.
 * @return The count of accented characters in the string.
 *
 * @complexity Time Complexity: O(n), where n is the length of the input string.
 */
int Menu::countAccentedCharacters(const std::string& str) {
    std::string accentedCharacters = "áéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãõÃÕçÇ";
    float count = 0;
    for (char c : str) {
        if (accentedCharacters.find(c) != std::string::npos) {
            count+=0.5;
        }
    }
    return int(count);
}
/**
 * @brief Displays all water reservoirs.
 *
 * @complexity Time Complexity: Time Complexity: O(V), where V is the number of vertices in the graph..
 */
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
        int n = countAccentedCharacters(water_res.getWaterReservoirName());
        cout << "│ " << left << setw(6) << "Name: " << right << left << setw(29+n) << water_res.getWaterReservoirName() << right << setw(6) << "Code: " << right << left << setw(8) << water_res.getCode() << right << "│" << endl;


    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}

/**
 * @brief Displays all pumping stations.
 *
 * @complexity Time Complexity: Time Complexity: O(V), where V is the number of vertices in the graph.
 */
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

/**
 * @brief Displays all delivery sites.
 *
 * @complexity Time Complexity: Time Complexity: O(V), where V is the number of vertices in the graph.
 */
void Menu::displayAllDeliverySites() const{
    std::unordered_set<DeliverySites> delivery_sites;
    for(auto del_sites : data_.getNetwork().getVertexSet()){
        if(del_sites->getType()==2){
            delivery_sites.insert(data_.findDeliverySite(del_sites->getInfo()));
        }
    }
    cout << "┌─ Delivery Sites ─────────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for(auto del_site : delivery_sites) {
        if (del_site.getCode() == "SuperSink") {
            continue;
        }
        int n = countAccentedCharacters(del_site.getCityName());
        cout << "│ " << left << setw(6) << "Name: " << right << left << setw(29+n) << del_site.getCityName() << right<< setw(6) << "Code: " << right << left << setw(8) << del_site.getCode() << right << "│" << endl;

    }
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
}

int Menu::compareWaterReservoirs(const unordered_map<string, DeliverySites>& delivery_sites_before) {
    auto network = data_.getNetwork();
    data_.edmondsKarp("SuperSource", "SuperSink");

    double maxflow = 0;

    for (auto adj: delivery_sites_before) {
        auto vertex = network.findVertex(adj.first);
        if (vertex == NULL) {
            cout << "Wrong City Code" << endl;
            return 1;
        }

        float sum = 0;
        for (auto edge: vertex->getAdj()) {
            sum += edge->getFlow();
        }
        maxflow += sum;
        int count = 0;
        for (auto it_before: delivery_sites_before) {
            if (adj.first == it_before.first) {
                count++;
                if (maxflow < it_before.second.getDemand()) {
                    if (adj.second.getCityName() == "SuperSink" || adj.second.getCityName() == "SuperSource") {
                        continue;
                    }
                    cout << "Cidade: " << adj.first << endl;
                    cout << " - Valor antigo: " << it_before.second.getDemand() << endl;
                    cout << " - Novo valor: " << maxflow << endl;
                    double difference = maxflow - it_before.second.getDemand();
                    cout << " - Diferença: " << difference << endl;
                }
            }
        }


        if (count == 0) {
            std::cout
                    << "Não houve alterações nos valores dos locais de entrega após a remoção do reservatório de água."
                    << std::endl;
        }

    }
}
