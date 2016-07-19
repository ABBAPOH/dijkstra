#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>

class Graph
{
public:
    Graph();

    void read(std::istream &s);
    void dump();
    void findWay(int from, int to);

    struct Vertex;
    using VertexPtr = std::shared_ptr<Vertex>;
    using VertexWeakPtr = std::shared_ptr<Vertex>;

    struct Edge
    {
        Edge() = default;
        Edge(int w, int v) : weight(w), vertex(v) {}

        int weight = 0;
        int vertex = 0;
    };

    struct Vertex
    {
        Vertex() = default;
        Vertex(const Vertex &other) = delete;
        Vertex &operator=(const Vertex &other) = delete;

//        std::vector<VertexWeakPtr> vertexes;
        std::vector<Edge> edges;
    };

private:
    using VertexMap = std::unordered_map<int, VertexPtr>;
    VertexMap _vertexes;
};

#endif // GRAPH_H
