#include "../includes/Data.h"
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;


/**
 * @brief Constructor for the Data class.
 *
 * @complexity Time Complexity: O(N), where N is the total number of records in all dataset files.
 */
Data::Data(bool largeDataset){
    if (largeDataset) {
        readPumpingStationsLarge();
        readDeliverySitesLarge();
        readWaterReservoirLarge();
        readPipesLarge();
        large_dataset_ = true;
    } else {
        readPumpingStations();
        readDeliverySites();
        readWaterReservoir();
        readPipes();
        large_dataset_ = false;
    }
    addSuperSourceAndSink("SuperSource", "SuperSink");
}

/**
 * @brief Reads water reservoir data from a Madeira CSV file.
 *
 * @complexity Time Complexity: O(R), where R is the number of water reservoir records in the file.
 */
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

/**
 * @brief Reads water reservoir data from a LargeDataSet CSV file.
 *
 * @complexity Time Complexity: O(R), where R is the number of water reservoir records in the file.
 */
void Data::readWaterReservoirLarge() {
    static const string WATER_RESERVOIRS_FILEPATH = "../dataset/Project1LargeDataSet/Project1LargeDataSet/Reservoir.csv";

    ifstream waterReservoirsFile(WATER_RESERVOIRS_FILEPATH);
    if (waterReservoirsFile.fail()) {
        ostringstream error_message;
        error_message << "Could not open file \"" << WATER_RESERVOIRS_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string header;
    getline(waterReservoirsFile, header);

    string water_reservoir_name, municipality, id_string, code_string, max_delivery_string, coma;
    while (getline(waterReservoirsFile, water_reservoir_name, ',')) {
        getline(waterReservoirsFile, municipality, ',');
        getline(waterReservoirsFile, id_string, ',');
        getline(waterReservoirsFile, code_string, ',');
        getline(waterReservoirsFile, max_delivery_string, '\r');
        getline(waterReservoirsFile, coma);

        int id = stoi(id_string);
        int max_delivery = stoi(max_delivery_string);
        WaterReservoir water_res(water_reservoir_name, municipality, id, code_string, max_delivery);
        water_reservoirs_.insert(water_res);
        network_.addVertex(code_string, 0);
    }
}

/**
 * @brief Reads pumping station data from a Madeira CSV file.
 *
 * @complexity Time Complexity: O(S), where S is the number of pumping station records in the file.
 */
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

/**
 * @brief Reads pumping station data from a LargeDataSet CSV file.
 *
 * @complexity Time Complexity: O(S), where S is the number of pumping station records in the file.
 */
void Data::readPumpingStationsLarge() {
    static const string PUMPING_STATIONS_FILEPATH = "../dataset/Project1LargeDataSet/Project1LargeDataSet/Stations.csv";

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
        getline(pumpingStationsFile, code, '\n');
        code.erase(remove(code.begin(), code.end(), '\r'), code.end());

        int id = stoi(id_string);
        PumpingStations pump_sta(id, code);
        pumping_stations_.insert(pump_sta);
        network_.addVertex(code, 1);
    }
}

/**
 * @brief Reads delivery site data from a Madeira CSV file.
 *
 * @complexity Time Complexity: O(D), where D is the number of delivery site records in the file.
 */
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

/**
 * @brief Reads delivery site data from a LargeDataSet CSV file.
 *
 * @complexity Time Complexity: O(D), where D is the number of delivery site records in the file.
 */
void Data::readDeliverySitesLarge() {
    static const string DELIVERY_SITES_FILEPATH = "../dataset/Project1LargeDataSet/Project1LargeDataSet/Cities.csv";

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
        population_string.erase(remove(population_string.begin(), population_string.end(), '\r'), population_string.end());
        DeliverySites del_site(city, id, code, demand, population_string);
        delivery_sites_.insert(del_site);
        network_.addVertex(code, 2);
    }
}

/**
 * @brief Reads pipe data from a Madeira CSV file.
 *
 * @complexity Time Complexity: O(P), where P is the number of pipe records in the file.
 */
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

/**
 * @brief Reads pipe data from a LargeDataSet CSV file.
 *
 * @complexity Time Complexity: O(P), where P is the number of pipe records in the file.
 */
void Data::readPipesLarge() {
    static const string PIPES_FILEPATH = "../dataset/Project1LargeDataSet/Project1LargeDataSet/Pipes.csv";

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

/**
 * @brief Retrieves the network graph.
 *
 * @complexity Time Complexity: O(1)
 */
Graph Data::getNetwork() const{
    return network_;
}

/**
* @brief Retrieves the set of water reservoirs.
*
* @complexity Time Complexity: O(1)
*/
unordered_set<WaterReservoir> Data::getWaterReservoirs() const {
    return water_reservoirs_;
}
/**
 * @brief Retrieves the set of pumping stations.
 *
 * @complexity Time Complexity: O(1)
 */
unordered_set<PumpingStations> Data::getPumpingStations() const {
    return pumping_stations_;
}

/**
 * @brief Retrieves the set of delivery sites.
 *
 * @complexity Time Complexity: O(1)
 */
unordered_set<DeliverySites> Data::getDeliverySites() const{
    return delivery_sites_;
}

/**
 * @brief Retrieves the set of pipes.
 *
 * @complexity Time Complexity: O(1)
 */
unordered_set<Pipes> Data::getPipes() const {
    return pipes_;
}

/**
 * @brief Finds a water reservoir by its code.
 *
 * @complexity Time Complexity: O(R), where R is the number of water reservoirs.
 */
WaterReservoir Data::findWaterReservoir(const string code) const {
    for(auto& it : water_reservoirs_){
        if(it.getCode()==code){
            return it;
        }
    }
    throw runtime_error("Water Reservoir not found");
}
/**
 * @brief Finds a pumping station by its code.
 *
 * @complexity Time Complexity: O(S), where S is the number of pumping stations.
 */
PumpingStations Data::findPumpingStation(const string code) const {
    for(auto& it : pumping_stations_){
        if(it.getPumpingStationCode()==code){
            return it;
        }
    }
    throw runtime_error("Pumping station not found");
}

/**
 * @brief Finds a delivery site by its code.
 *
 * @complexity Time Complexity: O(D), where D is the number of delivery sites.
 */
DeliverySites Data::findDeliverySite(const string code) const {
    for(auto& it : delivery_sites_) {
        if (it.getCode() == code) {
            return it;
        }
    }
    throw runtime_error("Delivery site not found");
}

/**
 * @brief Finds a pipe between two service points.
 *
 * @complexity Time Complexity: O(P), where P is the number of pipes.
 */
Pipes Data::findPipes(const string serv_point_a, const string serv_point_b) const {
    for(const auto& pipe : pipes_) {
        if ((pipe.getCitySourceName() == serv_point_a && pipe.getCitySinkName() == serv_point_b) ||
            (pipe.getCitySourceName() == serv_point_b && pipe.getCitySinkName() == serv_point_a)) {
            return pipe;
        }
    }
    throw runtime_error("Pipes not found");
}


/**
 * @brief Checks the water needs at all delivery sites and returns those with supply deficits.
 *
 * @return A vector of pairs containing the delivery site code and the amount of water in deficit.
 *
 * @complexity Time Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges.
 */
vector<pair<string, double>> Data::checkWaterNeeds() {
    // Aqui vamos utilizar um vector, invés de um map, pq uma vez que não existe benefício em utilizar map pq vamos ter de percorrer o vetor inteiro na mesma
    vector<pair<string, double>> deficits;
    for (auto vertex : network_.getVertexSet()) {
        if (vertex->getType() == 2 && vertex->getInfo() != "SuperSink") {
            DeliverySites del_site = findDeliverySite(vertex->getInfo());
            double demand = del_site.getDemand();



            double total_flow = 0;
            for (auto e : vertex->getIncoming()) {
                total_flow += e->getFlow();
            }

            if (total_flow < demand) {
                double deficit = demand - total_flow;
                deficits.push_back(make_pair(del_site.getCode(), deficit));
            }
        }
    }

    return deficits;
}


/**
 * @brief Adds a super source and a super sink to the graph.
 *
 * @param superSourceName Name of the super source.
 * @param superSinkName Name of the super sink.
 *
 * @complexity Time Complexity: O(V), where V is the number of vertices.
 */
void Data::addSuperSourceAndSink(const string& superSourceName, const string& superSinkName) {
    WaterReservoir super_source(superSourceName, "Municipality", 0, superSourceName, numeric_limits<int>::max());
    DeliverySites super_sink(superSinkName, 0, superSinkName, numeric_limits<double>::max(), "0");
    water_reservoirs_.insert(super_source);
    delivery_sites_.insert(super_sink);
    network_.addVertex(superSourceName, 0);
    network_.addVertex(superSinkName, 2);

    Vertex* superSource = network_.findVertex(superSourceName);
    Vertex* superSink = network_.findVertex(superSinkName);

    for (const WaterReservoir& vertex : water_reservoirs_) {
        network_.addEdge(superSource->getInfo(), vertex.getCode(), vertex.getMaxDelivery());

    }

    for (const DeliverySites& vertex : delivery_sites_) {
        network_.addEdge(vertex.getCode(), superSink->getInfo(), vertex.getDemand());

    }
}

/**
 * @brief Helper function to test and visit a vertex during the search for augmenting paths. Part of the Edmond's Karp algorithm
 *
 * @param q Queue of vertices to be visited.
 * @param e Edge that led to the vertex to be visited.
 * @param w The vertex to be visited.
 * @param residual The residual flow along the edge.
 *
 * @complexity Time Complexity: O(1)
 */
void Data::testAndVisit(queue<Vertex*>& q, Edge* e, Vertex* w, double residual) {
    if (!w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

/**
 * @brief Finds an augmenting path in the graph using the Edmonds-Karp algorithm.
 *
 * @param s The source vertex.
 * @param t The sink vertex.
 *
 * @return True if an augmenting path was found, False otherwise.
 *
 * @complexity Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
 */
bool Data::findAugmentingPath(Vertex* s, Vertex* t) {
    for (auto v : network_.getVertexSet()) {
        v->setVisited(false);
    }
    s->setVisited(true);
    queue<Vertex*> q;
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

/**
 * @brief Finds the minimum residual flow along the augmenting path.
 *
 * @param s The source vertex.
 * @param t The sink vertex.
 *
 * @return The minimum residual flow along the augmenting path.
 *
 * @complexity Time Complexity: O(V), where V is the number of vertices.
 */
double Data::findMinResidualAlongPath(Vertex* s, Vertex* t) {
    const double INF = numeric_limits<double>::max();
    double f = INF;
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        } else {
            f = min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

/**
 * @brief Augments the flow along the found augmenting path.
 *
 * @param s The source vertex.
 * @param t The sink vertex.
 * @param f The flow to be augmented along the path.
 *
 * @complexity Time Complexity: O(V), where V is the number of vertices.
 */
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

/**
 * @brief Runs the Edmonds-Karp algorithm to find the maximum flow.
 *
 * @param source The source vertex code.
 * @param target The target vertex code.
 *
 * @complexity Time Complexity: O(V * E^2), where V is the number of vertices and E is the number of edges.
 */
void Data::edmondsKarp(string source, string target) {
    Vertex* s = network_.findVertex(source);
    Vertex* t = network_.findVertex(target);
    if (s == nullptr || t == nullptr || s == t) {
        throw logic_error("Invalid source and/or target vertex");
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

/**
 * @brief Removes a water reservoir from the network.
 *
 * @param water_reservoir_code The code of the water reservoir to be removed.
 *
 * @complexity Time Complexity: O(1)
 */
void Data::removeWaterReservoir(const string &water_reservoir_code) {
    network_.removeVertex(water_reservoir_code);
    edmondsKarp("SuperSource", "SuperSink");
}

/**
 * @brief Removes a pumping station from the network.
 *
 * @param pumping_station_code The code of the pumping station to be removed.
 *
 * @complexity Time Complexity: O(1)
 */
void Data::removePumpingStations(const string &pumping_station_code) {
    network_.removeVertex(pumping_station_code);
    edmondsKarp("SuperSource", "SuperSink");
}

/**
 * @brief Removes a delivery site from the network.
 *
 * @param delivery_site_code The code of the delivery site to be removed.
 *
 * @complexity Time Complexity: O(1)
 */
void Data::removeDeliverySite(const string &delivery_site_code) {
    network_.removeVertex(delivery_site_code);
    edmondsKarp("SuperSource", "SuperSink");
}

/**
 * @brief Removes a pipe between two service points from the network.
 *
 * @param serv_site_a The code of the first service point.
 * @param serv_site_b The code of the second service point.
 *
 * @complexity Time Complexity: O(1)
 */
void Data::removePipe(const string &serv_site_a, const string &serv_site_b) {

    Pipes pipe = findPipes(serv_site_a,serv_site_b);
    pipes_.erase(pipe);
    if(pipe.getDirection()==1){
        network_.removeEdge(serv_site_a,serv_site_b);
    }else if(pipe.getDirection()==0){
        network_.removeEdge(serv_site_b,serv_site_a);
        network_.removeEdge(serv_site_a,serv_site_b);
    }
    edmondsKarp("SuperSource", "SuperSink");
}

/**
 * @brief Restores the graph to its initial state by reloading data from files.
 *
 * @complexity Time Complexity: O(N), where N is the total number of records in all dataset files.
 */
void Data::restoreGraph() {
    network_ = Graph();
    if (large_dataset_) {
        readWaterReservoirLarge();
        readPumpingStationsLarge();
        readDeliverySitesLarge();
        readPipesLarge();
    } else {
        readWaterReservoir();
        readPumpingStations();
        readDeliverySites();
        readPipes();
    }
    addSuperSourceAndSink("SuperSource","SuperSink");
    edmondsKarp("SuperSource","SuperSink");
}

/**
 * @brief Computes the average difference between pipe capacity and flow.
 *
 * @complexity Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
 */
double Data::computeAvgPipeDif() {
    double sum=0;
    int count=0;
    for(auto v: network_.getVertexSet()) {
        if(v->getInfo()!="SuperSource" & v->getInfo()!="SuperSink") {
            for(auto e :v->getAdj()) {
                if(e->getDest()->getInfo()!="SuperSource" & e->getDest()->getInfo()!="SuperSink")
                sum+=e->getWeight()-e->getFlow();
            }
            count+=v->getAdj().size();
        }
    }
    return round(sum/count*1000)/1000;
}

/**
 * @brief Computes the variance of pipe differences.
 *
 * @complexity Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
 */
double Data::computePipeDifVar() {
    double sum=0;
    double avg = computeAvgPipeDif();
    int c=0;
    for(auto v: network_.getVertexSet()) {
        if(v->getInfo()!="SuperSource" & v->getInfo()!="SuperSink") {
            for (auto e: v->getAdj()) {
                if(e->getDest()->getInfo()!="SuperSource" & e->getDest()->getInfo()!="SuperSink") {
                    sum = sum + (e->getWeight() - e->getFlow() - avg) * (e->getWeight() - e->getFlow() - avg);
                }
            }
            c += v->getAdj().size();
        }
    }
    return round(sum/c*1000)/1000;
}

/**
 * @brief Computes the maximum difference between pipe capacity and flow.
 *
 * @complexity Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.
 */
double Data::computePipeMaxDif() {
    int max=INT32_MIN;
    for(auto v: network_.getVertexSet()) {
        if(v->getInfo()!="SuperSource" & v->getInfo()!="SuperSink") {
            for(auto e :v->getAdj()) {
                if(e->getDest()->getInfo()!="SuperSource" & e->getDest()->getInfo()!="SuperSink") {
                    int dif = e->getWeight() - e->getFlow();
                    if (max < dif) {
                        max = dif;
                    }
                }
            }
        }

    }
    return max;
}

bool compareSecond(const pair<Edge*, double>& a, const pair<Edge*, double>& b) {
    return a.second < b.second;
}

/**
 * @brief Balances the load across the network by redistributing excess flow. Not Working
 *
 * @complexity Time Complexity: O()
 */
void Data::balanceLoadAcrossNetwork() {
    vector<pair<Vertex*,double>> v;
    for(DeliverySites city: delivery_sites_){
        v.push_back({network_.findVertex(city.getCode()), city.getDemand()});
    }
    for(auto p:v) {
        double flowDelivered=0;
        vector<pair<Edge*,double>> pri;
        for(Edge* e:p.first->getIncoming()) {
            flowDelivered+=e->getFlow();
            pri.push_back({e,e->getWeight()-e->getFlow()});
        }
        sort(pri.begin(), pri.end(), compareSecond);

        if(flowDelivered>p.second) {
            for(auto p:pri) {
                if(flowDelivered>p.first->getWeight()) {
                    p.first->setFlow(p.first->getWeight());
                    flowDelivered-=p.first->getWeight();
                }
                else if (flowDelivered>0 && flowDelivered<p.first->getWeight()) {
                    p.first->setFlow(flowDelivered);
                    flowDelivered=0;
                }

            }
        }
    }
}



/**
 * @brief Checks the balance of the network and prints relevant statistics. Depends on a method that is not working
 *
 * @complexity Time Complexity: O()
 */
void Data::checkBalance() {
    edmondsKarp("SuperSource","SuperSink");
    cout << computePipeMaxDif() << " " << computePipeDifVar() << " " << computeAvgPipeDif() << endl;
    balanceLoadAcrossNetwork();
    cout << computePipeMaxDif() << " " << computePipeDifVar() << " " << computeAvgPipeDif() << endl;
}

