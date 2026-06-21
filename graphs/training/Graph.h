#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"

#include <vector>
#include <functional>
#include <stack>

using std::vector;
using std::function;
using std::stack;

void printNodeValue(int n);

class Graph
{
public:
    Graph(const vector<vector<int>>& adjacencyList);

    void addEdge(int from, int to, bool isBidirectional = false);
    void addEdge(const Edge& e, bool isBidirectional = false);

    void bfs(function<void(int)> process = printNodeValue);
    void bfsDisconnected(function<void(int)> process = printNodeValue);
    void dfsIterative(function<void(int)> process = printNodeValue);
    void dfsRecursive(function<void(int)> process = printNodeValue);
    void dfsIterativeDisconnected(function<void(int)> process = printNodeValue);
    void dfsRecursiveDisconnected(function<void(int)> process = printNodeValue);
    
    bool isCyclicIterativeForUndirectedGraph();
    bool isCyclicRecursiveForUndirectedGraph();
    bool isCyclicIterativeForDirectedGraph();
    bool isCyclicRecursiveForDirectedGraph();

    // uses Kahn's Algorithm
    vector<int> getTopologicalOrder();

    int shortestDistance(int a, int b);
    int componentsCount();

    // uses Kosaraju's Algorithm
    vector<vector<int>> getSCCv1();

private:
    bool isCyclicRecursiveHelperForUndirectedGraph(int node, int parent, vector<bool>& visited);
    bool isCyclicRecursiveHelperForDirectedGraph(int node, vector<bool>& visited, vector<bool>& recStack);
    void bfsInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);
    void dfsIterativeInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);
    void dfsRecursiveInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);

    void dfsKosaraju1(int node, vector<bool>& visited, stack<int>& st);
    void dfsKosaraju2(int node, const vector<vector<int>>& reverseAdjancencyLists, vector<bool>& visited, vector<int>& scc);

    vector<Edge> getUniqueEdges();

private:
    vector<vector<int>> m_adjacencyList;
    vector<Edge> m_edgeList;
    uint m_nodeCount;
};

# endif
