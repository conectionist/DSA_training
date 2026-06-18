#ifndef GRAPH_H
#define GRAPH_H

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

    void bfs(function<void(int)> process = printNodeValue);
    void dfsIterative(function<void(int)> process = printNodeValue);
    void dfsRecursive(function<void(int)> process = printNodeValue);

    bool isCyclicIterative();
    bool isCyclicRecursive();

    // uses Kahn's Algorithm
    vector<int> getTopologicalOrder();

    int shortestDistance(int a, int b);
    int componentsCount();

    // uses Kosaraju's Algorithm
    vector<vector<int>> getSCCv1();

private:
    bool isCyclicRecursiveHelper(int node, vector<bool>& visited, vector<bool>& recStack);
    void bfsInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);
    void dfsIterativeInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);
    void dfsRecursiveInternal(vector<bool>& visited, int node, function<void(int)> process = printNodeValue);

    void dfsKosaraju1(int node, vector<bool>& visited, stack<int>& st);
    void dfsKosaraju2(int node, const vector<vector<int>>& reverseAdjancencyLists, vector<bool>& visited, vector<int>& scc);

private:
    vector<vector<int>> m_adjacencyList;
    uint m_nodeCount;
};

# endif
