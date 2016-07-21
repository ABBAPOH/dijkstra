#include "graph.h"

#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>

Graph::Graph()
{

}

void Graph::read(std::istream &s)
{
    VertexMap vertexes;

    int vertexCount = 0;
    s >> vertexCount;

    for (int i = 0; i < vertexCount; ++i) {
        auto vertex = std::make_shared<Vertex>();
        vertexes.emplace(i, vertex);
    }

    typedef std::pair<int, int> Egde;
    std::map<Egde, int> edges;

    int edgeCount = 0;
    s >> edgeCount;
    for (int i = 0; i < edgeCount; ++i) {
        const auto checkIndex = [vertexCount](int index) {
            if (index < 0 || index >= vertexCount) {
                throw std::runtime_error("Graph::read: Invalid vertex index: " +
                                         std::to_string(index));
            }
        };

        Egde e;
        int weight = 0;
        s >> e.first >> e.second >> weight;

        checkIndex(e.first);
        checkIndex(e.second);

        if (!edges.insert({e, weight}).second) {
            throw std::runtime_error("Graph::read: Duplicate edge [" +
                                     std::to_string(e.first) + "->" +
                                     std::to_string(e.second) + "]");
        }
    }

    for (auto item : edges) {
        const auto edge = item.first;
        const auto weight = item.second;
        const auto vertexFrom = vertexes[edge.first];
        const auto e = Edge(weight, edge.second);
        vertexFrom->edges.push_back(e);
    }

    _vertexes.swap(vertexes);
}

void Graph::dump()
{
    std::cout << "Graph {" << std::endl
              << "    vertexes: [" << std::endl;
    for (int i = 0; i < int(_vertexes.size()); ++i) {
        auto vertex = _vertexes[i];
        std::cout << "        " << i << "," << std::endl;
    }
    std::cout << std::endl << "    ]" << std::endl;
    std::cout << "}" << std::endl;
}

void Graph::findWay(int from, int to)
{
    int vertexCount = int(_vertexes.size());
    const auto checkIndex = [vertexCount](int index) {
        if (index < 0 || index >= vertexCount) {
            throw std::runtime_error("Graph::read: Invalid vertex index: " +
                                     std::to_string(index));
        }
    };

    checkIndex(from);
    checkIndex(to);

    auto vertexFrom = _vertexes[from];
    auto vertexTo = _vertexes[to];

    std::unordered_set<int> notVisitedVertexes;
    std::unordered_set<int> visitedVertexes;
    std::unordered_map<int, int> weights;

    for (int i = 0; i < vertexCount; ++i) {
        weights[i] = INT32_MAX;
        notVisitedVertexes.insert(i);
    }
    weights[from] = 0;

    while (!notVisitedVertexes.empty()) {
        int vertexId = 0;
        int weight = INT32_MAX;
        for (auto v : notVisitedVertexes) {
            if (weights[v] < weight) {
                weight = weights[v];
                vertexId = v;
            }
        }


    }
}
