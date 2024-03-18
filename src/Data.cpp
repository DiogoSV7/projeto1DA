#include "../includes/Data.h"
#include <fstream>
#include <sstream>
using namespace std;


Data::Data() {

    readPumpingStations();

    readDeliverySites();

    readWaterReservoir();

    readPipes();

    addSuperSourceAndSink("SuperSource", "SuperSink");
}

void Data::readWaterReservoir() {
    static const string WATER_RESERVOIRS_FILEPATH = "../dataset/Reservoirs_Madeira.csv";

    ifstream waterReservoirsFile(WATER_RESERVOIRS_FILEPATH);
    if(waterReservoirsFile.fail()){
        ostringstream error_message;
        error_message << "Could not open file \"" << WATER_RESERVOIRS_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string header;
    getline(waterReservoirsFile,header);

    string water_reservoir_name, municipality, id_string, code_string , max_delivery_string, coma;
    while(getline(waterReservoirsFile, water_reservoir_name, ',')) {
        getline(waterReservoirsFile, municipality, ',');
        getline(waterReservoirsFile, id_string, ',');
        getline(waterReservoirsFile, code_string, ',');
        getline(waterReservoirsFile, max_delivery_string, ',');
        getline(waterReservoirsFile,coma);

        int id = stoi(id_string);
        int max_delivery = stoi(max_delivery_string);
        WaterReservoir water_res(water_reservoir_name, municipality, id, code_string, max_delivery);
        water_reservoirs_.insert(water_res);
        network_.addVertex(code_string,0);
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
    string header;
    getline(pumpingStationsFile,header);

    string id_string, code, coma;
    while (getline(pumpingStationsFile, id_string, ',')) {
        if(id_string.empty()){
            break;
        }
        getline(pumpingStationsFile, code, ',');
        getline(pumpingStationsFile, coma);
        int id = stoi(id_string);
        PumpingStations pump_sta(id, code);
        pumping_stations_.insert(pump_sta);
        network_.addVertex(code, 1);
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

    string header;
    getline(deliverySitesFile, header);

    string line;
    while(getline(deliverySitesFile, line)) {
        stringstream ss(line);
        string city, id_string, code, demand_string, population_string;

        getline(ss, city, ',');
        getline(ss, id_string, ',');
        getline(ss, code, ',');
        getline(ss, demand_string, ',');
        getline(ss, population_string, ',');

        population_string.erase(remove(population_string.begin(), population_string.end(), '"'), population_string.end());
        int id = stoi(id_string);
        double demand = stod(demand_string);
        population_string.erase(remove(population_string.begin(), population_string.end(), ','), population_string.end());
        DeliverySites del_site(city, id, code, demand, population_string);
        delivery_sites_.insert(del_site);
        network_.addVertex(code, 2);
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

    string header;
    getline(pipesFile,header);

    string serv_site_a, serv_site_b, capacity_string, direction_string;
    while (getline(pipesFile, serv_site_a, ',')) {
        getline(pipesFile, serv_site_b, ',');
        getline(pipesFile, capacity_string, ',');
        getline(pipesFile, direction_string);
        int capacity = stoi(capacity_string);
        int direction = stoi(direction_string);
        Vertex* source = network_.findVertex(serv_site_a);
        Vertex* sink = network_.findVertex(serv_site_b);
        if (source != nullptr && sink != nullptr) {
            if (direction == 0) {
                Pipes pipe(serv_site_a, serv_site_b, capacity, direction);
                pipes_.insert(pipe);
                network_.addBidirectionalEdge(source->getInfo(), sink->getInfo(), capacity);
            } else {
                network_.addEdge(source->getInfo(), sink->getInfo(), capacity);
                Pipes pipe(serv_site_a, serv_site_b, capacity, direction);
                pipes_.insert(pipe);
            }
        }
    }
}

Graph Data::getNetwork() const{
    return network_;
}

unordered_set<WaterReservoir> Data::getWaterReservoirs() const {
    return water_reservoirs_;
}

unordered_set<PumpingStations> Data::getPumpingStations() const {
    return pumping_stations_;
}

unordered_set<DeliverySites> Data::getDeliverySites() const{
    return delivery_sites_;
}

WaterReservoir Data::findWaterReservoir(const std::string code) const {
    for(auto& it : water_reservoirs_){
        if(it.getCode()==code){
            return it;
        }
    }
    throw std::runtime_error("Water Reservoir not found");
}

PumpingStations Data::findPumpingStation(const std::string code) const {
    for(auto& it : pumping_stations_){
        if(it.getPumpingStationCode()==code){
            return it;
        }
    }
    throw std::runtime_error("Pumping station not found");
}

DeliverySites Data::findDeliverySite(const std::string code) const {
    for(auto& it : delivery_sites_) {
        if (it.getCode() == code) {
            return it;
        }
    }
    throw std::runtime_error("Delivery site not found");
}

Pipes Data::findPipes(const std::string serv_point_a, const std::string serv_point_b) const {
    for(const auto& pipe : pipes_) {
        if ((pipe.getCitySourceName() == serv_point_a && pipe.getCitySinkName() == serv_point_b) ||
            (pipe.getCitySourceName() == serv_point_b && pipe.getCitySinkName() == serv_point_a)) {
            return pipe;
        }
    }
    throw std::runtime_error("Pipes not found");
}


std::unordered_map<std::string, double> Data::maxWaterCity(const std::string& delivery_site_code) {
    Vertex* target_vertex = nullptr;
    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 2 && vertex->getInfo() == delivery_site_code) {
            target_vertex = vertex;
            break;
        }
    }

    if (target_vertex == nullptr) {
        throw std::logic_error("Delivery site with the specified code not found");
    }
    edmondsKarp("SuperSource", target_vertex->getInfo());

    std::unordered_map<std::string, double> max_water_map;
    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 0) {
            double max_flow = 0;
            for (auto e : vertex->getAdj()) {
                max_flow += e->getFlow();
            }
            max_water_map[vertex->getInfo()] = max_flow;
        }
    }

    return max_water_map;
}

std::vector<std::pair<string, double>> Data::checkWaterNeeds() {
    // Aqui vamos utilizar um vector, invés de um map, pq uma vez que não existe benefício em utilizar map pq vamos ter de percorrer o vetor inteiro na mesma
    std::vector<std::pair<std::string, double>> deficits;
    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 2 && vertex->getInfo() != "SuperSink") {
            DeliverySites del_site = findDeliverySite(vertex->getInfo());
            double demand = del_site.getDemand();

            edmondsKarp("SuperSource", del_site.getCode());

            double total_flow = 0;
            for (auto e : vertex->getIncoming()) {
                total_flow += e->getFlow();
            }

            if (total_flow < demand) {
                double deficit = demand - total_flow;
                deficits.push_back(std::make_pair(del_site.getCode(), deficit));
            }
        }
    }

    return deficits;
}

void Data::addSuperSourceAndSink(const std::string& superSourceName, const std::string& superSinkName) {
    WaterReservoir super_source(superSourceName, "Municipality", 0, superSourceName, std::numeric_limits<int>::max());
    DeliverySites super_sink(superSinkName, 0, superSinkName, std::numeric_limits<double>::max(), "0");
    water_reservoirs_.insert(super_source);
    delivery_sites_.insert(super_sink);
    network_.addVertex(superSourceName, 0);
    network_.addVertex(superSinkName, 2);

    Vertex* superSource = network_.findVertex(superSourceName);
    Vertex* superSink = network_.findVertex(superSinkName);

    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 0) {
            network_.addEdge(superSource->getInfo(), vertex->getInfo(), std::numeric_limits<double>::infinity());
        }
    }

    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 2) {
            network_.addEdge(vertex->getInfo(), superSink->getInfo(), std::numeric_limits<double>::infinity());
        }
    }
}

void Data::testAndVisit(std::queue<Vertex*>& q, Edge* e, Vertex* w, double residual) {
    if (!w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

bool Data::findAugmentingPath(Vertex* s, Vertex* t) {
    for (auto v : network_.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Vertex*> q;
    q.push(s);
    while (!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        for (auto e : v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        for (auto e : v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

double Data::findMinResidualAlongPath(Vertex* s, Vertex* t) {
    const double INF = std::numeric_limits<double>::max();
    double f = INF;
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        } else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

void Data::augmentFlowAlongPath(Vertex* s, Vertex* t, double f) {
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        } else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}

void Data::edmondsKarp(string source, string target) {
    Vertex* s = network_.findVertex(source);
    Vertex* t = network_.findVertex(target);
    if (s == nullptr || t == nullptr || s == t) {
        throw std::logic_error("Invalid source and/or target vertex");
    }
    for (auto v : network_.getVertexSet()) {
        for (auto e : v->getAdj()) {
            e->setFlow(0);
        }
    }
    while (findAugmentingPath(s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

void Data::removeWaterReservoir(const std::string &water_reservoir_code) {
    network_.removeVertex(water_reservoir_code);
}

/*vector<pair<std::string, double>> Data::removeWaterReservoir(const std::string &water_reservoir_code){
    network_.removeVertex(water_reservoir_code);
    water_reservoirs_.erase(findWaterReservoir(water_reservoir_code));
    vector<pair<string, double>> affectedCities = identifyAffectedCities(water_reservoir_code);
    return affectedCities;
}*/

void Data::removePumpingStations(const std::string &pumping_station_code) {
    network_.removeVertex(pumping_station_code);
}

void Data::removeDeliverySite(const std::string &delivery_site_code) {
    network_.removeVertex(delivery_site_code);
}

void Data::removePipe(const std::string &serv_site_a, const std::string &serv_site_b) {
    network_.removeEdge(serv_site_a,serv_site_b);
}

void Data::restoreGraph() {
    water_reservoirs_.clear();
    pumping_stations_.clear();
    delivery_sites_.clear();
    pipes_.clear();

    readWaterReservoir();
    readPumpingStations();
    readDeliverySites();
    readPipes();
    addSuperSourceAndSink("SuperSource", "SuperSink");
}

/*std::unordered_set<std::string> Data::evaluateReservoirImpact(const std::string& reservoirCode) {
    // Step 1: Find the water reservoir to be removed
    WaterReservoir reservoir;
    try {
        reservoir = findWaterReservoir(reservoirCode);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return {}; // Return empty set if reservoir not found
    }

    // Step 2: Remove the water reservoir from the graph
    removeWaterReservoir(reservoirCode);

    // Step 3: Evaluate impact on delivery sites
    std::unordered_set<std::string> affectedCities;
    for (const auto& deliverySite : delivery_sites_) {
        // Simulate max flow after removing reservoir
        std::unordered_map<std::string, double> maxWaterMap;
        try {
            maxWaterMap = maxWaterCity(deliverySite.getCode());
        } catch (const std::logic_error& e) {
            std::cerr << e.what() << std::endl;
            return {}; // Return empty set if delivery site not found
        }

        // Check if demand is met
        if (maxWaterMap.find(deliverySite.getCode()) != maxWaterMap.end()) {
            if (maxWaterMap[deliverySite.getCode()] < deliverySite.getDemand()) {
                affectedCities.insert(deliverySite.getCode());
            }
        }
    }

    // Step 4: Restore graph to original state
    restoreGraph();

    return affectedCities;
}*/
