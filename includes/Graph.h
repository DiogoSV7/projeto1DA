// Original code by Gonçalo Leão
// Updated by DA 2023/2024 Team

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string> // Include string header for std::string usage

// Forward declarations of WaterReservoir, PumpingStations, and DeliverySites classes
class WaterReservoir;
class PumpingStations;
class DeliverySites;

class Vertex;

class Edge {
public:
    Edge(Vertex* source, Vertex* dest, double weight) : source_(source), dest_(dest), weight_(weight) {}

    Vertex* getSource() const { return source_; }
    Vertex* getDest() const { return dest_; }
    double getWeight() const { return weight_; }

private:
    Vertex* source_;
    Vertex* dest_;
    double weight_;
};

class Vertex {
public:
    Vertex(WaterReservoir wr) : water_reservoir_(wr), id_(wr.getCode()), index_(0) {}
    Vertex(PumpingStations ps) : pumping_station_(ps), id_(ps.getPumpingStationCode()), index_(1) {}
    Vertex(DeliverySites ds) : delivery_site_(ds), id_(ds.getCode()), index_(2) {}

    void addEdge(Edge* edge) {
        edges_.push_back(edge);
    }

    const std::vector<Edge*>& getEdges() const { return edges_; }

    // Getters
    std::string getCode() const { return id_; }
    int getIndex() const { return index_; }

private:
    std::string id_;
    int index_; // 0 for WaterReservoir, 1 for PumpingStations, 2 for DeliverySites
    WaterReservoir water_reservoir_;
    PumpingStations pumping_station_;
    DeliverySites delivery_site_;

    std::vector<Edge*> edges_;
};

class Graph {
public:
    Vertex* findVertex(const std::string& id) const {
        auto it = vertices_.find(id);
        return (it != vertices_.end()) ? it->second : nullptr;
    }

    void addVertex(Vertex* vertex) {
        vertices_[vertex->getCode()] = vertex;
    }

    void addEdge(Vertex* source, Vertex* dest, double weight) {
        Edge* edge = new Edge(source, dest, weight);
        source->addEdge(edge);
        edges_.push_back(edge);
    }

    // Getters
    const std::unordered_map<std::string, Vertex*>& getVertices() const { return vertices_; }
    const std::vector<Edge*>& getEdges() const { return edges_; }

private:
    std::unordered_map<std::string, Vertex*> vertices_; // Map of vertex ID to vertex pointer
    std::vector<Edge*> edges_; // Vector of edges
};

#endif /* DA_TP_CLASSES_GRAPH */
