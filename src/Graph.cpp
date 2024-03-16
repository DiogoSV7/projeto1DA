
#include "../includes/Graph.h"

Vertex::Vertex(const std::string& in, const int type) : type_(type), info(in), visited(false), processing(false), indegree(0), dist(0), path(nullptr), queueIndex(0) {}


Edge* Vertex::addEdge(Vertex* d, double w) {
    auto newEdge = new Edge(this, d, w);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

bool Vertex::removeEdge(const std::string& in) {
    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge* edge = *it;
        Vertex* dest = edge->getDest();
        if (dest->getInfo() == in) {
            it = adj.erase(it);
            deleteEdge(edge);
            removedEdge = true;
        }
        else {
            it++;
        }
    }
    return removedEdge;
}

void Vertex::removeOutgoingEdges() {
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge* edge = *it;
        it = adj.erase(it);
        deleteEdge(edge);
    }
}

bool Vertex::operator<(const Vertex& vertex) const {
    return this->dist < vertex.dist;
}

std::string Vertex::getInfo() const {
    return this->info;
}

std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge* Vertex::getPath() const {
    return this->path;
}

std::vector<Edge*> Vertex::getIncoming() const {
    return this->incoming;
}

void Vertex::setInfo(const std::string& info) {
    this->info = info;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setProcessing(bool processing) {
    this->processing = processing;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

int Vertex::getType() const {
    return type_;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge* path) {
    this->path = path;
}

void Vertex::deleteEdge(Edge* edge) {
    Vertex* dest = edge->getDest();
    auto it = dest->incoming.begin();
    while (it != dest->incoming.end()) {
        if ((*it)->getOrig()->getInfo() == info) {
            it = dest->incoming.erase(it);
        }
        else {
            it++;
        }
    }
    delete edge;
}

Edge::Edge(Vertex* orig, Vertex* dest, double w) : orig(orig), dest(dest), weight(w), reverse(nullptr), flow(0) {}

Vertex* Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex* Edge::getOrig() const {
    return this->orig;
}

Edge* Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

double Edge::getFlow() const {
    return flow;
}

void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge* reverse) {
    this->reverse = reverse;
}

void Edge::setFlow(double flow) {
    this->flow = flow;
}

/*Graph::~Graph() {                                                                !!!!!!!!!!!!!!!!!!
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}*/

Vertex* Graph::findVertex(const std::string& in) const {
    auto it = vertexMap.find(in);
    if (it != vertexMap.end()) {
        return it->second;
    }
    return nullptr;
}

bool Graph::addVertex(const std::string& in, const int type) {
    if (findVertex(in) != nullptr) {
        return false;
    }
    Vertex* vertex = new Vertex(in,type);
    vertexSet.push_back(vertex);
    vertexMap[in] = vertex;
    return true;
}

bool Graph::removeVertex(const std::string& in) {
    auto it = vertexMap.find(in);
    if (it == vertexMap.end()) {
        return false;
    }
    Vertex* v = it->second;
    for (auto u : vertexSet) {
        u->removeEdge(v->getInfo());
    }
    vertexSet.erase(std::remove(vertexSet.begin(), vertexSet.end(), v), vertexSet.end());
    vertexMap.erase(it);
    delete v;
    return true;
}

bool Graph::addEdge(const std::string& source, const std::string& dest, double w) {
    Vertex* v1 = findVertex(source);
    Vertex* v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr) {
        return false;
    }
    v1->addEdge(v2, w);
    return true;
}

bool Graph::removeEdge(const std::string& source, const std::string& dest) {
    Vertex* srcVertex = findVertex(source);
    if (srcVertex == nullptr) {
        return false;
    }
    return srcVertex->removeEdge(dest);
}

bool Graph::addBidirectionalEdge(const std::string& source, const std::string& dest, double w) {
    Vertex* v1 = findVertex(source);
    Vertex* v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr) {
        return false;
    }
    Edge* e1 = v1->addEdge(v2, w);
    Edge* e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}

std::unordered_map<std::string, Vertex*> Graph::getVertexMap() const {
    return vertexMap;
}

std::vector<std::string> Graph::dfs() const {
    std::vector<std::string> res;
    for (auto v : vertexSet) {
        v->setVisited(false);
    }
    for (auto v : vertexSet) {
        if (!v->isVisited()) {
            dfsVisit(v, res);
        }
    }
    return res;
}

std::vector<std::string> Graph::dfs(const std::string& source) const {
    std::vector<std::string> res;
    Vertex* s = findVertex(source);
    if (s == nullptr) {
        return res;
    }
    for (auto v : vertexSet) {
        v->setVisited(false);
    }
    dfsVisit(s, res);
    return res;
}

void Graph::dfsVisit(Vertex* v, std::vector<std::string>& res) const {
    v->setVisited(true);
    res.push_back(v->getInfo());
    for (auto& e : v->getAdj()) {
        Vertex* w = e->getDest();
        if (!w->isVisited()) {
            dfsVisit(w, res);
        }
    }
}

std::vector<std::string> Graph::bfs(const std::string& source) const {
    std::vector<std::string> res;
    Vertex* s = findVertex(source);
    if (s == nullptr) {
        return res;
    }
    for (auto v : vertexSet) {
        v->setVisited(false);
    }
    std::queue<Vertex*> q;
    q.push(s);
    s->setVisited(true);
    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();
        res.push_back(v->getInfo());
        for (auto& e : v->getAdj()) {
            Vertex* w = e->getDest();
            if (!w->isVisited()) {
                q.push(w);
                w->setVisited(true);
            }
        }
    }
    return res;
}

bool Graph::isDAG() const {
    for (auto v : vertexSet) {
        v->setVisited(false);
        v->setProcessing(false);
    }
    for (auto v : vertexSet) {
        if (!v->isVisited()) {
            if (!dfsIsDAG(v)) {
                return false;
            }
        }
    }
    return true;
}

bool Graph::dfsIsDAG(Vertex* v) const {
    v->setVisited(true);
    v->setProcessing(true);
    for (auto e : v->getAdj()) {
        Vertex* w = e->getDest();
        if (w->isProcessing()) {
            return false;
        }
        if (!w->isVisited()) {
            if (!dfsIsDAG(w)) {
                return false;
            }
        }
    }
    v->setProcessing(false);
    return true;
}

std::vector<std::string> Graph::topsort() const {
    std::vector<std::string> res;
    for (auto v : vertexSet) {
        v->setIndegree(0);
    }
    for (auto v : vertexSet) {
        for (auto e : v->getAdj()) {
            unsigned int indegree = e->getDest()->getIndegree();
            e->getDest()->setIndegree(indegree + 1);
        }
    }
    std::queue<Vertex*> q;
    for (auto v : vertexSet) {
        if (v->getIndegree() == 0) {
            q.push(v);
        }
    }
    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();
        res.push_back(v->getInfo());
        for (auto e : v->getAdj()) {
            Vertex* w = e->getDest();
            w->setIndegree(w->getIndegree() - 1);
            if (w->getIndegree() == 0) {
                q.push(w);
            }
        }
    }
    if (res.size() != vertexSet.size()) {
        res.clear();
    }
    return res;
}

int Graph::findVertexIdx(const std::string& in) const {
    for (unsigned i = 0; i < vertexSet.size(); i++) {
        if (vertexSet[i]->getInfo() == in) {
            return i;
        }
    }
    return -1;
}

void Graph::deleteMatrix(int** m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++) {
            if (m[i] != nullptr) {
                delete[] m[i];
            }
        }
        delete[] m;
    }
}

void Graph::deleteMatrix(double** m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++) {
            if (m[i] != nullptr) {
                delete[] m[i];
            }
        }
        delete[] m;
    }
}







