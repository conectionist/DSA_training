#include "Graph.h"
#include "UnionFind.h"

#include <bits/stdc++.h>

using std::queue;
using std::stack;

Graph::Graph(const vector<vector<int>>& adjacencyList)
{
    m_adjacencyList = adjacencyList;
    m_nodeCount = adjacencyList.size();
    m_edgeList.clear();

    for(int from = 0; from < m_nodeCount; ++from)
        for(int to : m_adjacencyList[from])
            m_edgeList.push_back(Edge(from, to));
}

void Graph::addEdge(int from, int to, bool isBidirectional)
{
    if(from < 0 || from >= m_nodeCount || to < 0 || to >= m_nodeCount)
        return;

    m_adjacencyList[from].push_back(to);
    m_edgeList.push_back(Edge(from, to));

    if(isBidirectional)
    {
        m_adjacencyList[to].push_back(from);
        m_edgeList.push_back(Edge(to, from));
    }
}

void Graph::addEdge(const Edge& e, bool isBidirectional)
{
    addEdge(e.from, e.to, isBidirectional);
}

void Graph::bfs(function<void(int)> process)
{
    if(m_nodeCount == 0)
        return;

    vector<bool> visited(m_nodeCount, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();
        process(current);

        for(const auto neighbor : m_adjacencyList[current])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void Graph::bfsDisconnected(function<void(int)> process)
{
    if(m_nodeCount == 0)
        return;

    vector<bool> visited(m_nodeCount, false);

    for(int i = 0 ; i < m_nodeCount ; i++)
        if(!visited[i])
            bfsInternal(visited, i, process);
}

void Graph::dfsIterative(function<void(int)> process)
{
    if(m_nodeCount == 0)
        return;

    vector<bool> visited(m_nodeCount, false);
    stack<int> st;
    
    st.push(0);

    while(!st.empty())
    {
        auto current = st.top();
        st.pop();

        if(visited[current])
            continue;

        process(current);
        visited[current] = true;

        for(const auto neighbor : m_adjacencyList[current])
            if(!visited[neighbor])
                st.push(neighbor);
    }
}

void Graph::dfsRecursive(function<void(int)> process)
{
    if(m_nodeCount == 0)
        return;

    vector<bool> visited(m_nodeCount, false);

    dfsRecursiveInternal(visited, 0, process);
}

void Graph::dfsIterativeDisconnected(function<void(int)> process)
{
    if(m_nodeCount == 0)
        return;

    vector<bool> visited(m_nodeCount, false);

    for(int i = 0 ; i < m_nodeCount ; i++)
        if(!visited[i])
            dfsIterativeInternal(visited, i, process);
}

void Graph::dfsRecursiveDisconnected(function<void(int)> process)
{
    (void)process;
}

bool Graph::isCyclicIterativeForUndirectedGraph()
{
    UnionFind dsu(m_nodeCount);

    for(const auto& [from, to] : getUniqueEdges())
    {
        int rootX = dsu.find(from);
        int rootY = dsu.find(to);
        
        if(!dsu.unite(from, to))
            return true;
    }

    return false;
}

bool Graph::isCyclicRecursiveForUndirectedGraph()
{
    if(m_nodeCount == 0)
        return false;

    vector<bool> visited(m_nodeCount, false);

    for (int i = 0; i < m_nodeCount; i++) 
        if (!visited[i]) 
            if(isCyclicRecursiveHelperForUndirectedGraph(i, -1, visited))
                return true;
    
    return false;
}

bool Graph::isCyclicIterativeForDirectedGraph()
{
    auto topoSortedNodes = getTopologicalOrder();

    return topoSortedNodes.size() != m_nodeCount;
}

bool Graph::isCyclicRecursiveForDirectedGraph()
{
    vector<bool> visited(m_nodeCount, false);
    vector<bool> recStack(m_nodeCount, false);

    for(int i = 0 ; i < m_nodeCount ; i++)
        if(isCyclicRecursiveHelperForDirectedGraph(i, visited, recStack))
            return true;

    return false;
}

vector<int> Graph::getTopologicalOrder()
{
    vector<int> inDegrees(m_nodeCount, 0);
    vector<int> topoSortedNodes;
    queue<int> q;

    for(int i = 0 ; i < m_nodeCount ; i++)
        for(auto neigh : m_adjacencyList[i])
            inDegrees[neigh]++;
    
    for(int i = 0 ; i < m_nodeCount ; i++)
        if(inDegrees[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        topoSortedNodes.push_back(current);

        for(auto n : m_adjacencyList[current])
        {
            inDegrees[n]--;

            if(inDegrees[n] == 0)
                q.push(n);
        }
    }

    return topoSortedNodes;
}

int Graph::shortestDistance(int a, int b)
{
    queue<int> q;
    vector<bool> visited(m_nodeCount, false);
    vector<int> distances(m_nodeCount, -1);

    int count = 0;

    q.push(a);
    visited[a] = true;
    distances[a] = 0;

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        if(current == b)
            return distances[current];
        
        for(int neighbor : m_adjacencyList[current])
            if(!visited[neighbor])
            {
                visited[current] = true;
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
    }

    return -1;
}

int Graph::componentsCount()
{
    if(m_nodeCount == 0)
        return 0;

    vector<bool> visited(m_nodeCount, false);
    int count = 0;

    for(int i = 0 ; i < m_nodeCount ; i++)
        if(!visited[i])
        {
            bfsInternal(visited, i);
            count++;
        }

    return count;
}

vector<vector<int>> Graph::getSCCv1()
{
    stack<int> st;
    vector<bool> visited(m_nodeCount, false);

    for(int i = 0 ; i < m_nodeCount ; i++)
        if(!visited[i])
            dfsKosaraju1(i, visited, st);
    
    vector<vector<int>> reverseAdj(m_nodeCount);

    for(int i = 0 ; i < m_nodeCount ; i++)
        for(const auto neighbor : m_adjacencyList[i])
            reverseAdj[neighbor].push_back(i);
        
    for(int i = 0 ; i < m_nodeCount ; i++)
        visited[i] = false;

    vector<vector<int>> sccs;
    
    while(!st.empty())
    {
        auto current = st.top();
        st.pop();

        if(!visited[current])
        {
            vector<int> scc;
            dfsKosaraju2(current, reverseAdj, visited, scc);
            sccs.push_back(scc);
        }
    }

    return sccs;
}

bool Graph::isCyclicRecursiveHelperForUndirectedGraph(int node, int parent, vector<bool>& visited)
{
    visited[node] = true;

    for(const auto neighbor : m_adjacencyList[node])
    {
        if(neighbor == parent)
            continue;

        if(visited[neighbor] || isCyclicRecursiveHelperForUndirectedGraph(neighbor, node, visited))
            return true;
    }

    return false;
}

bool Graph::isCyclicRecursiveHelperForDirectedGraph(int node, vector<bool> &visited, vector<bool> &recStack)
{
    if(!visited[node])
    {
        visited[node] = true;
        recStack[node] = true;

        for(int neighbor : m_adjacencyList[node])
        {
            if(!visited[neighbor] && isCyclicRecursiveHelperForDirectedGraph(neighbor, visited, recStack))
                return true;
            else if(recStack[neighbor])
                return true;
        }
    }

    recStack[node] = false;

    return false;
}

void Graph::bfsInternal(vector<bool> &visited, int node, function<void(int)> process)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();
        process(current);

        for(const auto neighbor : m_adjacencyList[current])
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
    }
}

void Graph::dfsIterativeInternal(vector<bool> &visited, int node, function<void(int)> process)
{
    stack<int> st;
    st.push(node);
    
    while(!st.empty())
    {
        auto current = st.top();
        st.pop();

        if(visited[current])
            continue;

        process(current);
        visited[current] = true;

        for(int neighbor : m_adjacencyList[current])
            if(!visited[neighbor])
                st.push(neighbor);
    }
}

void Graph::dfsRecursiveInternal(vector<bool> &visited, int node, function<void(int)> process)
{
    process(node);
    visited[node] = true;

    for(const auto neighbor : m_adjacencyList[node])
        if(!visited[neighbor])
            dfsRecursiveInternal(visited, neighbor, process);
}

void Graph::dfsKosaraju1(int node, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for(auto neighbor : m_adjacencyList[node])
        if(!visited[neighbor])
            dfsKosaraju1(neighbor, visited, st);

    st.push(node);
}

void Graph::dfsKosaraju2(int node, const vector<vector<int>>& reverseAdjancencyLists, vector<bool> &visited, vector<int> &scc)
{
    visited[node] = true;

    scc.push_back(node);

    for(const int neghbor : reverseAdjancencyLists[node])
        if(!visited[neghbor])
            dfsKosaraju2(neghbor, reverseAdjancencyLists, visited, scc);
}

void printNodeValue(int n)
{
    (void)n;
}

vector<Edge> Graph::getUniqueEdges()
{
    vector<Edge> uniqueEdges;

    for(const auto& edge : m_edgeList)
    {
        bool alreadyExists = false;

        for(const auto& existing : uniqueEdges)
        {
            if((existing.from == edge.from && existing.to == edge.to) ||
               (existing.from == edge.to && existing.to == edge.from))
            {
                alreadyExists = true;
                break;
            }
        }

        if(!alreadyExists)
            uniqueEdges.push_back(edge);
    }

    return uniqueEdges;
}
