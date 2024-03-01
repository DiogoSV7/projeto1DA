#include "../includes/Data.h"
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;


Data::Data() {
    readPipes();
    readPumpingStations();
    readDeliverySites();
    readWaterReservoir();
}

void Data::readWaterReservoir() {
    static const string WATER_RESERVOIRS_FILEPATH = "../dataset/Reservoirs_Madeira.csv";

    ifstream waterReservoirsFile(WATER_RESERVOIRS_FILEPATH);
    if(waterReservoirsFile.fail()){
        ostringstream error_message;
        error_message << "Could not open file \"" << WATER_RESERVOIRS_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string water_reservoir_name, municipality, id_string, code , max_delivery_string, max_numeric_limits;
    waterReservoirsFile.ignore(numeric_limits<streamsize>::max(), '\n');
    while(getline(waterReservoirsFile, water_reservoir_name, ',')) {
        getline(waterReservoirsFile, municipality, ',');
        getline(waterReservoirsFile, id_string, ',');
        getline(waterReservoirsFile, code, ',');
        getline(waterReservoirsFile, max_delivery_string, ',');
        getline(waterReservoirsFile, max_numeric_limits);

        int id = stoi(id_string);
        int max_delivery = stoi(max_delivery_string);
        WaterReservoir water_res(water_reservoir_name, municipality, id, code, max_delivery);
        Vertex new_vertex(water_res);
        network_.addVertex(&new_vertex);
    }
}

void Data::readPumpingStations() {
    static const string PUMPING_STATIONS_FILEPATH = "../dataset/Stations_Madeira.csv";

    ifstream pumpingStationsFile(PUMPING_STATIONS_FILEPATH);
    if(pumpingStationsFile.fail()){
        ostringstream error_message;
        error_message << "Could not open file \"" << PUMPING_STATIONS_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string id_string, code, max_delivery_string;
    pumpingStationsFile.ignore(numeric_limits<streamsize>::max(), '\n');
    while(getline(pumpingStationsFile, id_string, ',')) {
        getline(pumpingStationsFile, code, ',');
        getline(pumpingStationsFile, max_delivery_string);
        int id = stoi(id_string);
        PumpingStations pump_sta(id,code);
        Vertex new_vertex(pump_sta);
        network_.addVertex(&new_vertex);
    }
}

void Data::readDeliverySites() {
    static const string DELIVERY_SITES_FILEPATH = "../dataset/Cities_Madeira.csv";

    ifstream deliverySitesFile(DELIVERY_SITES_FILEPATH);
    if(deliverySitesFile.fail()){
        ostringstream error_message;
        error_message << "Could not open file \"" << DELIVERY_SITES_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string city, id_string, code, demand_string, population_string;
    deliverySitesFile.ignore(numeric_limits<streamsize>::max(), '\n');
    while(getline(deliverySitesFile, city, ',')) {
        getline(deliverySitesFile, id_string, ',');
        getline(deliverySitesFile, code, ',');
        getline(deliverySitesFile, demand_string, ',');
        getline(deliverySitesFile, population_string, ',');
        int id = stoi(id_string);
        double demand = stod(demand_string);
        DeliverySites del_site(city, id, code, demand, population_string);
        Vertex new_vertex(del_site);
        network_.addVertex(&new_vertex);
    }
}

void Data::readPipes() {
    static const string PIPES_FILEPATH = "../dataset/Pipes_Madeira.csv";

    ifstream pipesFile(PIPES_FILEPATH);
    if (pipesFile.fail()) {
        ostringstream error_message;
        error_message << "Could not open file \"" << PIPES_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }
    string serv_site_a, serv_site_b, capacity_string, direction_string;
    pipesFile.ignore(numeric_limits<streamsize>::max(), '\n');
    while (getline(pipesFile, serv_site_a, ',')) {
        getline(pipesFile, serv_site_b, ',');
        getline(pipesFile, capacity_string, ',');
        getline(pipesFile, direction_string, ',');
        int capacity = stoi(capacity_string);
        int direction = stoi(direction_string);
        Pipes pipe(serv_site_a, serv_site_b, capacity, direction);
        for (auto& entry : network_.getVertices()){
            if(network_.findVertex(serv_site_a)!= nullptr && network_.findVertex(serv_site_b)){
                Vertex* service_site_a = network_.findVertex(serv_site_a);
                Vertex* service_site_b = network_.findVertex(serv_site_b);
                network_.addEdge(service_site_a, service_site_b, capacity);
            }
        }
    }
}
Graph Data::getNetwork(){
    return network_;
}
