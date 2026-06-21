#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "WeightedEdge.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

struct NodePath
{
    int cost;
    int prev;
};

class WeightedGraph
{
public:
    WeightedGraph(int nodeCount);
    WeightedGraph(const vector<vector<WeightedEdge>>& adjacencyList);
    void addEdge(int from, int to, int weight, bool isBidirectional = false);
    void addEdge(const WeightedEdge& e, bool isBidirectional = false);
    int getEdgeCount() const;
    vector<NodePath> dijkstra(int from);
    vector<NodePath> bellmanFord(int from);
    vector<vector<int>> floydWarshall();
    WeightedGraph prim();
    WeightedGraph kruskal();
    WeightedGraph borukva();

    string toString();

private:
    vector<vector<WeightedEdge>> m_adjacencyList;
    vector<WeightedEdge> m_edgeList;
    int m_nodeCount;
};

#endif
