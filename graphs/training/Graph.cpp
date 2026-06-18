#include "Graph.h"

Graph::Graph(const vector<vector<int>>& adjacencyList)
{
    m_adjacencyList = adjacencyList;
    m_nodeCount = adjacencyList.size();
}

void Graph::bfs(function<void(int)> process)
{
    (void)process;
}

void Graph::dfsIterative(function<void(int)> process)
{
    (void)process;
}

void Graph::dfsRecursive(function<void(int)> process)
{
    (void)process;
}

bool Graph::isCyclicIterative()
{
    return false;
}

bool Graph::isCyclicRecursive()
{
    return false;
}

vector<int> Graph::getTopologicalOrder()
{
    return {};
}

int Graph::shortestDistance(int a, int b)
{
    (void)a;
    (void)b;
    return -1;
}

int Graph::componentsCount()
{
    return 0;
}

vector<vector<int>> Graph::getSCCv1()
{
    return {};
}

bool Graph::isCyclicRecursiveHelper(int node, vector<bool>& visited, vector<bool>& recStack)
{
    (void)node;
    (void)visited;
    (void)recStack;
    return false;
}

void Graph::bfsInternal(vector<bool>& visited, int node, function<void(int)> process)
{
    (void)visited;
    (void)node;
    (void)process;
}

void Graph::dfsIterativeInternal(vector<bool>& visited, int node, function<void(int)> process)
{
    (void)visited;
    (void)node;
    (void)process;
}

void Graph::dfsRecursiveInternal(vector<bool>& visited, int node, function<void(int)> process)
{
    (void)visited;
    (void)node;
    (void)process;
}

void Graph::dfsKosaraju1(int node, vector<bool>& visited, stack<int>& st)
{
    (void)node;
    (void)visited;
    (void)st;
}

void Graph::dfsKosaraju2(int node, const vector<vector<int>>& reverseAdjancencyLists, vector<bool>& visited, vector<int>& scc)
{
    (void)node;
    (void)reverseAdjancencyLists;
    (void)visited;
    (void)scc;
}

void printNodeValue(int n)
{
    (void)n;
}
