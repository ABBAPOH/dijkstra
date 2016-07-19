#include "graph.h"

#include <set>
#include <unordered_set>
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
    std::set<Egde> edges;

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
        s >> e.first >> e.second;

        checkIndex(e.first);
        checkIndex(e.second);

        if (!edges.insert(e).second) {
            throw std::runtime_error("Graph::read: Duplicate edge [" +
                                     std::to_string(e.first) + "->" +
                                     std::to_string(e.second) + "]");
        }
    }

    for (auto edge : edges) {
        const auto vertexFrom = vertexes[edge.first];
        const auto vertexTo = vertexes[edge.second];
        vertexFrom->vertexes.push_back(vertexTo);
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

    std::list<VertexPtr> vertexes;
    vertexes.push_back(vertexFrom);

    while (!vertexes.empty()) {

    }
}
