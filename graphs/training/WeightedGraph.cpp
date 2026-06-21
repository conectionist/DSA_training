#include "WeightedGraph.h"
#include "UnionFind.h"

#include <climits>
#include <sstream>
#include <queue>
#include <utility>
#include <algorithm>

using std::stringstream;
using std::priority_queue;
using std::pair;

WeightedGraph::WeightedGraph(int nodeCount) : m_adjacencyList(nodeCount),
                                              m_nodeCount(nodeCount)
{}

WeightedGraph::WeightedGraph(const vector<vector<WeightedEdge>>& adjacencyList) : m_adjacencyList(adjacencyList),
                                                                                 m_nodeCount(static_cast<int>(adjacencyList.size()))
{}

void WeightedGraph::addEdge(int from, int to, int weight, bool isBidirectional)
{
    m_adjacencyList[from].push_back(WeightedEdge(from, to, weight));
    m_edgeList.push_back(WeightedEdge(from, to, weight));

    if(isBidirectional)
    {
        m_adjacencyList[to].push_back(WeightedEdge(to, from, weight));
        m_edgeList.push_back(WeightedEdge(to, from, weight));
    }
}

void WeightedGraph::addEdge(const WeightedEdge& e, bool isBidirectional)
{
    addEdge(e.from, e.to, e.weight, isBidirectional);
}

int WeightedGraph::getEdgeCount() const
{
    return static_cast<int>(m_edgeList.size());
}

vector<NodePath> WeightedGraph::dijkstra(int from)
{
    vector<bool> visited(m_nodeCount, false);
    vector<NodePath> shortestPaths(m_nodeCount, {INT_MAX, -1});

    shortestPaths[from].cost = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> minHeap;
    minHeap.push({0, from});

    while(!minHeap.empty())
    {
        auto [currentCost, current] = minHeap.top();
        minHeap.pop();

        if(visited[current])
            continue;

        if(currentCost != shortestPaths[current].cost)
            continue;

        visited[current] = true;

        for(const auto& neighbor : m_adjacencyList[current])
        {
            if(visited[neighbor.to])
                continue;

            int candidateCost = shortestPaths[current].cost + neighbor.weight;
            if(candidateCost < shortestPaths[neighbor.to].cost)
            {
                shortestPaths[neighbor.to].cost = candidateCost;
                shortestPaths[neighbor.to].prev = current;
                minHeap.push({candidateCost, neighbor.to});
            }
        }
    }

    return shortestPaths;
}

vector<NodePath> WeightedGraph::bellmanFord(int from)
{
    vector<NodePath> results(m_nodeCount, {INT_MAX, -1});

    results[from].cost = 0;

    for(int i = 0 ; i < m_nodeCount - 1 ; i++)
    {
        bool noUpdates = true;

        for(const auto& edge : m_edgeList)
        {
            if(results[edge.from].cost == INT_MAX)
                continue;

            if(results[edge.to].cost > results[edge.from].cost + edge.weight)
            {
                results[edge.to].cost = results[edge.from].cost + edge.weight;
                results[edge.to].prev = edge.from;

                noUpdates = false;
            }
        }

        if(noUpdates)
            break;
    }

    for(const auto& edge : m_edgeList)
    {
        if(results[edge.from].cost == INT_MAX)
            continue;

        if(results[edge.to].cost > results[edge.from].cost + edge.weight)
            throw std::runtime_error("Negative cycle detected!");
    }

    return results;
}

vector<vector<int>> WeightedGraph::floydWarshall()
{
    int n = m_nodeCount;
    vector<vector<int>> results(n, vector<int>(n, INT_MAX));

    for(int i = 0 ; i < n ; i++)
        results[i][i] = 0;

    for(const auto& edge : m_edgeList)
        results[edge.from][edge.to] = edge.weight;

    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(results[i][k] != INT_MAX && results[k][j] != INT_MAX)
                    results[i][j] = std::min(results[i][j], results[i][k] + results[k][j]);

    return results;
}

WeightedGraph WeightedGraph::prim()
{
    return WeightedGraph(m_nodeCount);
}

WeightedGraph WeightedGraph::kruskal()
{
    WeightedGraph mst(m_nodeCount);
    UnionFind dsu(m_nodeCount);
    int count = 0;
    
    auto sortedEdgeList = m_edgeList;
    std::sort(sortedEdgeList.begin(), sortedEdgeList.end());

    for(const auto& edge : sortedEdgeList)
        if(dsu.unite(edge.from, edge.to))
        {
            mst.addEdge(edge);
            count++;

            if(count == m_nodeCount - 1)
                break;
        }

    return mst;
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
