#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator>(const Edge& other) const
    {
        return weight > other.weight;
    }

    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

struct NodePath
{
    int cost;
    int prev;
};

class WeightedGraph
{
public:
    WeightedGraph(int nodeCount);
    WeightedGraph(const vector<vector<Edge>>& adjacencyList);
    void addEdge(int from, int to, int weight, bool isBidirectional = false);
    void addEdge(const Edge& e, bool isBidirectional = false);
    int getEdgeCount() const;
    vector<NodePath> dijkstra(int from);
    vector<NodePath> bellmanFord(int from);
    vector<vector<int>> floydWarshall();
    WeightedGraph prim();
    WeightedGraph kruskal();
    WeightedGraph borukva();

    string toString();

private:
    vector<vector<Edge>> m_adjacencyList;
    vector<Edge> m_edgeList;
    int m_nodeCount;
};

#endif
