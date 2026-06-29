#include "WeightedGraph.h"
#include "UnionFind.h"

#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <queue>
#include <sstream>
#include <utility>

using std::pair;
using std::priority_queue;

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

vector<NodePath> WeightedGraph::dijkstra(int source)
{
    vector<bool> visited(m_nodeCount, false);
    vector<NodePath> shortestPaths(m_nodeCount, {INT_MAX, -1});

    // pair.first == cost
    // pair.second == to
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> minHeap;

    minHeap.push({0, source});
    shortestPaths[source] = {0, -1};

    while(!minHeap.empty())
    {
        auto currentNode = minHeap.top().second;
        minHeap.pop();

        if(visited[currentNode])
            continue;

        visited[currentNode] = true;

        for(const auto& edge : m_adjacencyList[currentNode])
        {
            auto& neighbor = edge.from;
            auto& neighborCost = edge.weight;

            if(visited[neighbor])
                continue;

            int candidateCost = shortestPaths[currentNode].cost + neighborCost;

            if(candidateCost < shortestPaths[neighbor].cost)
            {
                shortestPaths[neighbor].cost = candidateCost;
                shortestPaths[neighbor].prev = currentNode;
                minHeap.push({candidateCost, neighbor});
            }
        }
    }

    return shortestPaths;
}

vector<NodePath> WeightedGraph::bellmanFord(int from)
{
    vector<NodePath> results(m_nodeCount, {INT_MAX, -1});

    results[from].cost = 0;

    for(int i = 1 ; i <= m_nodeCount - 1 ; i++)
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
    WeightedGraph mst(m_nodeCount);
    vector<bool> visited(m_nodeCount, false);
    priority_queue<WeightedEdge, vector<WeightedEdge>, std::greater<WeightedEdge>> minHeap;
    int nodeCount = 0;
    int startNode = 0;

    visited[startNode] = true;

    for(const auto& neighbor : m_adjacencyList[startNode])
        minHeap.push(neighbor);

    while(!minHeap.empty() && nodeCount < m_nodeCount - 1)
    {
        auto cheapest = minHeap.top();
        minHeap.pop();

        if(visited[cheapest.to])
            continue;

        mst.addEdge(cheapest, true);
        nodeCount++;

        visited[cheapest.to] = true;

        for(const auto& neighbor : m_adjacencyList[cheapest.to])
            if(!visited[neighbor.to])
                minHeap.push(neighbor);

    }

    return mst;
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
    int n = m_nodeCount;
    WeightedGraph mst(n);
    UnionFind dsu(n);

    int componentsCount = n;

    while(componentsCount > 1)
    {
        vector<int> cheapest(n, -1);

        for(int i = 0 ; i < m_edgeList.size() ; i++)
        {
            auto& edge = m_edgeList[i];

            int rootX = dsu.find(edge.from);
            int rootY = dsu.find(edge.to);

            if(rootX == rootY)
                continue;

            if(cheapest[rootX] == -1 || edge.weight < m_edgeList[cheapest[rootX]].weight)
                cheapest[rootX] = i;
            if(cheapest[rootY] == -1 || edge.weight < m_edgeList[cheapest[rootY]].weight)
                cheapest[rootY] = i;
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(cheapest[i] == -1)
                continue;

            auto& edge = m_edgeList[cheapest[i]];

            if(dsu.unite(edge.from, edge.to))
            {
                mst.addEdge(edge);
                componentsCount--;
            }
        }
    }

    return mst;
}

string WeightedGraph::toString()
{
    std::stringstream ss;

    for(const auto& edge : m_edgeList)
        ss << "(" << edge.from << "," << edge.to << "," << edge.weight << ")\n";

    return ss.str();
}
