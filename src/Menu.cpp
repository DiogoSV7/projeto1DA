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
    data_.edmondsKarp("SuperSource", "SuperSink");
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
        if((key-'0')>5 ||(key-'0')<1){
            if(key=='Q'){}

            else{
                cout << endl << "Invalid option!" << endl;
                break;
            }
        }
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
                cout << "│     [Q] Exit                                     │" << endl;
                cout << "│" << setw(53) << "│" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key1;
                if((key1-'0')>2 ||(key1-'0')<1){
                    if(key1=='Q'){}

                    else{
                        cout << endl << "Invalid option!" << endl;
                        break;
                    }
                }
                switch (key1) {
                    case '1': {
                        vector<string> v;
                        for(DeliverySites city: data_.getDeliverySites()){
                            v.push_back(city.getCode());
                        }
                        if(displayMaxWater(v)==0){
                        }
                        break;
                    }
                    case '2': {
                        string city;
                        cout << "Choose a city: ";
                        cin >> city;
                        auto vertex = data_.getNetwork().findVertex(city);
                        if (vertex == NULL) {
                            continue;
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
                cout << "│     [Q] Exit                                     │" << endl;
                cout << "│" << setw(53) << "│" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key2;
                if((key2-'0')>5 ||(key2-'0')<1){
                    if(key2=='Q'){}

                    else{
                        cout << endl << "Invalid option!" << endl;
                        break;
                    }
                }
                unordered_map<string, pair<DeliverySites, int>> delivery_sites_before = getDeliverySitesBefore();
                switch (key2) {
                    case '1': {
                        string water_res_code;
                        cout << "Insert the Water Reservoir code:";
                        cin >> water_res_code;
                        data_.findWaterReservoir(water_res_code);

                        data_.removeWaterReservoir(water_res_code);
                        break;
                    }
                    case '2': {
                        string pumping_station_code;
                        cout << "Insert the Pumping Station code:";
                        cin >> pumping_station_code;
                        data_.findPumpingStation(pumping_station_code);
                        data_.removePumpingStations(pumping_station_code);
                        break;
                    }
                    case '3': {
                        string delivery_site_code;
                        cout << "Insert the Delivery Site code:";
                        cin >> delivery_site_code;
                        data_.findDeliverySite(delivery_site_code);
                        data_.removeDeliverySite(delivery_site_code);
                        break;
                    }
                    case '4': {
                        string serv_site_a, serv_site_b;
                        cout << "Insert the Service Site A code:";
                        cin >> serv_site_a;
                        data_.findDeliverySite(serv_site_a);
                        cout << "Insert the Service Site B code:";
                        cin >> serv_site_b;
                        data_.findDeliverySite(serv_site_b);
                        data_.findPipes(serv_site_a,serv_site_b);
                        data_.removePipe(serv_site_a,serv_site_b);
                        break;
                    }
                    case '5': {
                        data_.restoreGraph();
                        break;
                    }
                    case 'Q':{
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                if((key2!='Q') && (key2!='5'))
                    showDiferences(delivery_sites_before);

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
        if(!flag){
            cout << "See you next time!"<< endl;
            break;
        }
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
int Menu::extractNumberFromCode(const string& code) {
    return stoi(code.substr(2));
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
    ofstream outputFile("../saveddata/max_water_output.txt", ios::app);
    auto network= data_.getNetwork();

    cities.erase(remove(cities.begin(), cities.end(), "SuperSink"), cities.end());
    double maxflow=0;
    cout<<"┌── Max Water Flow ────────────────────────────────┐"<<endl;
    cout << "│" << setw(53) << "│" << endl;

    sort(cities.begin(), cities.end(), [this](const string& a, const string& b) {
        return extractNumberFromCode(a) < extractNumberFromCode(b);
    });
    if (outputFile.is_open()) {
        for (auto adj: cities) {
            auto vertex = network.findVertex(adj);
            if (vertex == NULL) {
                continue;
            }

            float sum = 0;
            for (auto edge: vertex->getAdj()) {
                sum += edge->getFlow();
            }
            maxflow+=sum;
            cout << "│" << setw(7) << adj << " : " << left << setw(40) << sum << right << "│" << endl;
            outputFile <<  setw(7) << adj << " : " << left << setw(40) << sum << right <<  endl;
        }
        if(cities.size()+1==data_.getDeliverySites().size()) {
            cout << "│                                                  │" << endl;
            cout << "│" << setw(9) << "MaxFlow" << " : " << left << setw(38) << maxflow << right << "│"
                      << endl;
            outputFile << setw(9) << "MaxFlow" << " : " << left << setw(38) << maxflow << right
                       << endl << endl;
        }
        outputFile.close();
    }else {
        cerr << "Error: Unable to open output file!" << endl;
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
        cout << "All delivery sites are adequately supplied. No deficits found." << endl;
        return;
    }

    cout << "┌── Water Deficits ────────────────────────────────┐" << endl;
    cout << "│" << setw(53) << "│" << endl;
    for (const auto& pair : water_needs_vector) {
        cout << "│ " << left << setw(20) << "Delivery Site code: " << left << setw(10) << pair.first << left << setw(10) << "Deficit: " << left << setw(9) <<  pair.second  << right << "│" << endl;
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
    cout << "│     [4] Display Pipes                            │" << endl;
    cout << "│     [Q] Quit Display Menu                        │" << endl;
    cout << "│" << setw(53) << "│" << endl;
    drawBottom();
    cout << "Choose an option: ";
    cin >> key;
    if((key-'0')>5 ||(key-'0')<1){
        if(key=='Q'){}

        else{
            cout << endl << "Invalid option!" << endl;
            return;
        }
    }
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
        case '4': {
            displayAllPipes();
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
int Menu::countAccentedCharacters(const string& str) {
    string accentedCharacters = "áéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãõÃÕçÇ";
    float count = 0;
    for (char c : str) {
        if (accentedCharacters.find(c) != string::npos) {
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

    unordered_set<WaterReservoir> reservoirs;
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
    unordered_set<PumpingStations> pumping_stations;
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
    unordered_set<DeliverySites> delivery_sites;
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

/**
 * @brief Displays all pipes.
 *
 * @complexity Time Complexity: O(P), where P is the number of pipes.
 */
void Menu::displayAllPipes() const {

    cout << "┌─ Pipes ────────────────────────────────────────────────────┐" << endl;
    cout << "│" << setw(63) << "│" << endl;

    for(const auto& pipe : data_.getPipes()) {
        cout << "│ " << left << setw(8) << "Source: " << right << setw(5) << pipe.getCitySourceName()
             << setw(8) << "Sink: " << setw(5) << pipe.getCitySinkName()
             << setw(14) << "Capacity: " << setw(3) << pipe.getCapacity()
             << setw(13) << "Direction: " << setw(2) << pipe.getDirection() << " │" << endl;
    }
    cout << "│" << setw(63) << "│" << endl;
    cout << "└────────────────────────────────────────────────────────────┘" << endl;
}

/**
 * @brief Retrieves delivery site information before any changes.
 *
 * This function retrieves information about delivery sites before any changes have been made to the data.
 * It constructs and returns an unordered map containing pairs of delivery site information and their corresponding maximum flow values.
 *
 * @return An unordered map containing pairs of delivery site information and their corresponding maximum flow values.
 */
unordered_map<string, pair<DeliverySites, int>> Menu::getDeliverySitesBefore() {
    unordered_map<string, pair<DeliverySites, int>> delivery_sites_before;
    for (const auto &delivery_site: data_.getDeliverySites()) {
        int maxflow=0;
        auto vertex = data_.getNetwork().findVertex(delivery_site.getCode());
        if (vertex == NULL) {
            continue;
        }

        float sum = 0;
        for (auto edge: vertex->getAdj()) {
            sum += edge->getFlow();
        }
        maxflow+=sum;
        delivery_sites_before[delivery_site.getCode()].first = delivery_site;
        delivery_sites_before[delivery_site.getCode()].second= maxflow;
    }
    return delivery_sites_before;
}

/**
 * @brief Displays differences in city data and saves them to a file.
 *
 * This function displays the differences in city data between the current state
 * and a previous state and saves the information to a file named "affected_cities_output.txt".
 *
 * @param delivery_sites_before An unordered map containing the city data before the changes.
 */
void Menu::showDiferences(unordered_map<string, pair<DeliverySites, int>> delivery_sites_before) {
    int count =0;
    ofstream outputFile("/Users/diogovieira/CLionProjects/projeto1DA/saveddata/affected_cities_output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }


    cout << "┌─ City Diferences ──────────────────────────────────────────┐" << endl;
    for(auto vertex: data_.getNetwork().getVertexSet()){
        if (vertex == NULL || vertex->getType() !=2) {
            continue;
        }
        auto info=vertex->getInfo();
        auto delivery= data_.findDeliverySite(info);
        int maxflow=0;


        float sum = 0;
        for (auto edge: vertex->getAdj()) {
            sum += edge->getFlow();
        }
        maxflow+=sum;

        if(delivery.getCode() == info){
            if(maxflow!=delivery_sites_before[info].second) {
                if(count==0){count=1;}
                cout << "│" << right << setw(63) << "│" << endl;
                outputFile << endl;
                cout << "│ " << setw(6) << "  Cidade: " << delivery.getCode();
                outputFile <<  setw(6) << "  Cidade: " << delivery.getCode();

                if (delivery.getDemand() > maxflow) {
                    cout << " - IN DEFICE" << setw(37) << "│" << endl;
                    outputFile << " - IN DEFICE" << setw(37) << endl;
                }
                else
                    cout << right << setw(49) << "│" << endl;
                    outputFile << endl;
                    cout << "│ " << left << setw(6) << " - Old Value  : " << fixed << setprecision(2) << setw(8)
                         << right << delivery_sites_before[info].second
                         << right << setw(38) << "│" << endl;
                    outputFile  << left << setw(6) << " - Old Value  : " << fixed << setprecision(2) << setw(8)
                         << right << delivery_sites_before[info].second
                         << right << setw(38) <<  endl;
                    cout << "│ " << left << setw(6) << " - New Value  : " << fixed << setprecision(2) << setw(8)
                         << right << maxflow << right << setw(38) << "│" << endl;
                    outputFile << left << setw(6) << " - New Value  : " << fixed << setprecision(2) << setw(8)
                         << right << maxflow << right << setw(38) <<  endl;
                    double difference = maxflow - delivery_sites_before[info].second;
                    cout << "│ " << left << setw(6) << " - Difference : " << right << fixed
                              << setw(8) << difference << right << setw(38) << "│" << endl;
                    outputFile << left << setw(6) << " - Difference : " << right << fixed
                         << setw(8) << difference << right << setw(38) << endl;


            }
        }
    }
    if(count ==0) {
        cout << "│" << right << setw(63) << "│" << endl;
        outputFile << endl << endl;
        cout << "│" << "                    No diferences found!                    " << "│" << endl;
    }
    cout << "│" << right << setw(63) << "│" << endl;
    cout << "└────────────────────────────────────────────────────────────┘" << endl;
}