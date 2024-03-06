#include "../includes/Data.h"
#include <fstream>
#include <sstream>
using namespace std;


template<class T>
Data<T>::Data() {
    readPipes();
    readPumpingStations();
    readDeliverySites();
    readWaterReservoir();
}

template<class T>
void Data<T>::readWaterReservoir() {
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
        Vertex<T> water_res(water_reservoir_name, municipality, id, code_string, max_delivery);
        network_.addVertex(water_res);
    }
}
template<class T>
void Data<T>::readPumpingStations() {
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
        Vertex<T> pump_sta(id, code);
        network_.addVertex(pump_sta);
    }
}
template<class T>
void Data<T>::readDeliverySites() {
    static const string DELIVERY_SITES_FILEPATH = "../dataset/Cities_Madeira.csv";

    ifstream deliverySitesFile(DELIVERY_SITES_FILEPATH);
    if(deliverySitesFile.fail()){
        ostringstream error_message;
        error_message << "Could not open file \"" << DELIVERY_SITES_FILEPATH << '"';
        throw ios_base::failure(error_message.str());
    }

    string header;
    getline(deliverySitesFile,header);

    string city, id_string, code, demand_string, population_string;
    while(getline(deliverySitesFile, city, ',')) {
        getline(deliverySitesFile, id_string, ',');
        getline(deliverySitesFile, code, ',');
        getline(deliverySitesFile, demand_string, ',');
        getline(deliverySitesFile, population_string);
        int id = stoi(id_string);
        double demand = stod(demand_string);
        Vertex<T> del_site(city, id, code, demand, population_string);
        network_.addVertex(del_site);
    }
}
template<class T>
void Data<T>::readPipes() {
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
        Vertex<T>* source = network_.findVertex(serv_site_a);
        Vertex<T>* sink = network_.findVertex(serv_site_b);
        if (source != nullptr && sink != nullptr) {
            if (direction == 0) {
                network_.addBidirectionalEdge(source, sink, capacity);
            } else {
                network_.addEdge(source->getValue(), sink->getValue(), capacity);
            }
        }
    }
}
template<class T>
Graph<T> Data<T>::getNetwork(){
    return network_;
}
template<class T>
int Data<T>::maxWaterCity(const string& city_name){


    return 0;
}
// Function to test the given vertex 'w' and visit it if conditions are met
template <class T>
void testAndVisit(std::queue< Vertex<T>*> &q, Edge<T> *e, Vertex<T> *w, double residual) {
    // Check if the vertex 'w' is not visited and there is residual capacity
    if (! w->isVisited() && residual > 0) {
    // Mark 'w' as visited, set the path through which it was reached, and enqueue it
    w->setVisited(true);
    w->setPath(e);
    q.push(w);
    }
}
// Function to find an augmenting path using Breadth-First Search
template <class T>
bool findAugmentingPath(Graph<T> *g, Vertex<T> *s, Vertex<T> *t) {
// Mark all vertices as not visited
    for(auto v : g->getVertexSet()) {
        v->setVisited(false);
    }
// Mark the source vertex as visited and enqueue it
    s->setVisited(true);
    std::queue<Vertex<T> *> q;
    q.push(s);
// BFS to find an augmenting path
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
// Process outgoing edges
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
// Process incoming edges
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
// Return true if a path to the target is found, false otherwise
    return t->isVisited();
}
template <class T>
double findMinResidualAlongPath(Vertex<T> *s, Vertex<T> *t) {
    double f = INF;
// Traverse the augmenting path to find the minimum residual capacity
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
// Return the minimum residual capacity
    return f;
}
// Function to augment flow along the augmenting path with the given flow value
template <class T>
void augmentFlowAlongPath(Vertex<T> *s, Vertex<T> *t, double f) {
// Traverse the augmenting path and update the flow values accordingly
for (auto v = t; v != s; ) {
    auto e = v->getPath();
    double flow = e->getFlow();
    if (e->getDest() == v) {
        e->setFlow(flow + f);
        v = e->getOrig();
        }
    else {
        e->setFlow(flow - f);
        v = e->getDest();
        }
    }
}
template <class T>
void edmondsKarp(Graph<T> *g, int source, int target) {
// Find source and target vertices in the graph
    Vertex<T>* s = g->findVertex(source);
    Vertex<T>* t = g->findVertex(target);
// Validate source and target vertices
    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");
// Initialize flow on all edges to 0
    for (auto v : g->getVertexSet()) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
// While there is an augmenting path, augment the flow along the path
    while( findAugmentingPath(g, s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}