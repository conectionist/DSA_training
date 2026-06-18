#include "WeightedGraph.h"
#include "UnionFind.h"

#include <climits>
#include <sstream>

using std::stringstream;

WeightedGraph::WeightedGraph(int nodeCount) : m_adjacencyList(nodeCount),
                                              m_nodeCount(nodeCount)
{}

WeightedGraph::WeightedGraph(const vector<vector<Edge>>& adjacencyList) : m_adjacencyList(adjacencyList),
                                                                          m_nodeCount(adjacencyList.size())
{}

void WeightedGraph::addEdge(int from, int to, int weight, bool isBidirectional)
{
    m_adjacencyList[from].push_back({from, to, weight});
    m_edgeList.push_back({from, to, weight});

    if(isBidirectional)
    {
        m_adjacencyList[to].push_back({to, from, weight});
        m_edgeList.push_back({to, from, weight});
    }
}

void WeightedGraph::addEdge(const Edge& e, bool isBidirectional)
{
    addEdge(e.from, e.to, e.weight, isBidirectional);
}

int WeightedGraph::getEdgeCount() const
{
    return static_cast<int>(m_edgeList.size());
}

vector<NodePath> WeightedGraph::dijkstra(int from)
{
    (void)from;
    return vector<NodePath>(m_nodeCount, {INT_MAX, -1});
}

vector<NodePath> WeightedGraph::bellmanFord(int from)
{
    (void)from;
    return vector<NodePath>(m_nodeCount, {INT_MAX, -1});
}

vector<vector<int>> WeightedGraph::floydWarshall()
{
    int n = m_nodeCount;
    vector<vector<int>> results(n, vector<int>(n, INT_MAX));

    for(int i = 0; i < n; ++i)
        results[i][i] = 0;

    return results;
}

WeightedGraph WeightedGraph::prim()
{
    return WeightedGraph(m_nodeCount);
}

WeightedGraph WeightedGraph::kruskal()
{
    return WeightedGraph(m_nodeCount);
}

WeightedGraph WeightedGraph::borukva()
{
    return WeightedGraph(m_nodeCount);
}

string WeightedGraph::toString()
{
    stringstream ss;

    for(const auto& edge : m_edgeList)
        ss << "(" << edge.from << "," << edge.to << "," << edge.weight << ")\n";

    return ss.str();
}
