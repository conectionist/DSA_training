#ifndef GRAPH_EXAMPLES_H
#define GRAPH_EXAMPLES_H

#include "graph_tests.h"

#include <iostream>

using std::cout, std::endl;

inline void runPractice()
{
    cout << "\n============================================\n" << endl;
    // ----------------------------------------------------------
    // Basic graph examples
    // Uncomment the one you want to run.
    // ----------------------------------------------------------

    // cout << "BFS traversal:" << endl;
    // g.bfs(process);
    // cout << endl;

    // cout << "DFS (iterative) traversal:" << endl;
    // g.dfsIterative(process);
    // cout << endl;

    // cout << "DFS (recursive) traversal:" << endl;
    // g.dfsRecursive(process);
    // cout << endl;

    // cout << "Topological order:" << endl;
    // auto topo = g.getTopologicalOrder();
    // printVector(topo);

    Graph g(adjacencyListUndirectedGraph);
    int a = 0;
    int b = 1;
    cout << "The shortest distance from " << a << " to " << b << " is "
         << g.shortestDistance(a, b) << endl;

    // Graph g1(adjacencyListUndirectedGraph);
    // Graph g2(adjacencyListUndirectedGraph3Comp);
    // cout << "Graph 1 has " << g1.componentsCount() << " connected component(s)" << endl;
    // cout << "Graph 2 has " << g2.componentsCount() << " connected component(s)" << endl;

    // cout << "Graph contains a cycle (iterative): "
    //      << (g.isCyclicIterativeForUndirectedGraph() ? "yes" : "no") << endl;

    // cout << "Graph contains a cycle (recursive): "
    //      << (gCyclic.isCyclicRecursive() ? "yes" : "no") << endl;

    // Graph g(adjacencyList1);
    // Graph gCyclic(adjacencyListWithCycle);
    // cout << "Graph contains a cycle (iterative): "
    //      << (g.isCyclicIterativeForDirectedGraph() ? "yes" : "no") << endl;
    // cout << "Graph contains a cycle (iterative): "
    //      << (gCyclic.isCyclicIterativeForDirectedGraph() ? "yes" : "no") << endl;

    // Graph g(adjacencyList2);
    // auto sccs = g.getSCCv1();
    // cout << "The graph has " << sccs.size() << " component(s):\n";
    // for (const auto& scc : sccs)
    //     printVector(scc);
    
    cout << "\n============================================\n" << endl;
}

#endif
