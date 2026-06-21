#ifndef GRAPH_TESTS_H
#define GRAPH_TESTS_H

#include <iostream>
#include <bits/stdc++.h>

#include "training/Graph.h"
#include "training/WeightedGraph.h"
#include "training/UnionFind.h"

using std::cout, std::endl;
using std::vector;
using std::queue;
using std::string;

vector<vector<int>> adjacencyList1 = 
{
    {1},
    {2},
    {3},
    {},
    {5},
    {1, 2}
};

vector<vector<int>> adjacencyList2 = 
{
    {4},
    {},
    {5},
    {2, 4},
    {0},
    {1, 2}
};

vector<vector<int>> adjacencyList3 = 
{
    {1,2},
    {0,3,4},
    {0,4},
    {1,5},
    {1,2,6},
    {3,7},
    {4,7},
    {5,6}
};

vector<vector<int>> adjacencyList4 = 
{
    {1},
    {2,3,4},
    {0,3},
    {},
    {5,6},
    {7},
    {5},
    {6}
};

vector<vector<int>> adjacencyListUndirectedGraph = 
{
    {3},
    {0,2,3},
    {1},
    {1}
};

vector<vector<int>> adjacencyListUndirectedGraphWithCycle = 
{
    {1,3},
    {0,2,3},
    {1},
    {1}
};

vector<vector<int>> adjacencyListWithCycle = 
{
    {1},
    {2},
    {3, 5},
    {},
    {5},
    {1}
};

vector<vector<int>> adjacencyListUndirectedGraph3Comp = 
{
    {},
    {3},
    {},
    {}
};

//auto& adj = adjacencyList1;

//Graph g(adj);
//Graph gCyclic(adjacencyListWithCycle);

void process(int val) {
    cout << val + 1 << " ";
};

void printVector(const vector<int>& v)
{
    if(v.empty())
        return;

    cout << "[";

    int i;
    for(i = 0 ; i < v.size() - 1 ; i++)
        cout << v[i] << ",";

    cout << v[i] << "]\n";
}

void printWeightedAdjacencyList(vector<vector<WeightedEdge>> wadj)
{
    for(int i = 0 ; i < wadj.size() ; i++)
        for(const auto& edge : wadj[i])
            cout << "Going from " << i << " to " << edge.to << " costs " << edge.weight << endl;
}

string getEntirePath(const vector<NodePath>& shortestPaths, int from, int to)
{
    vector<int> nodes;

    while(to != from)
    {
        nodes.push_back(to);
        to = shortestPaths[to].prev;
    }

    nodes.push_back(from);

    if(nodes.size() == 1)
        return std::to_string(nodes[0]);

    string s;
    for(int i = nodes.size() - 1 ; i > 0 ; i--)
        s += std::to_string(nodes[i]) + " --> ";

    s += std::to_string(nodes[0]);

    return s;
}

#endif
