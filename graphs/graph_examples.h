#ifndef GRAPH_EXAMPLES_H
#define GRAPH_EXAMPLES_H

#include "graph_tests.h"

#include <iostream>

using std::cout, std::endl;

inline void runPractice()
{
    cout << "\n============================================\n" << endl;
    cout << "Graph practice runner" << endl;
    cout << "Uncomment one block in this file to run it." << endl;
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

    // cout << "Shortest distance from 4 to 3: "
    //      << g.shortestDistance(4, 3) << endl;

    // cout << "Number of connected components: "
    //      << g.componentsCount() << endl;

    // cout << "Graph contains a cycle (iterative): "
    //      << (g.isCyclicIterative() ? "yes" : "no") << endl;

    // cout << "Graph contains a cycle (recursive): "
    //      << (gCyclic.isCyclicRecursive() ? "yes" : "no") << endl;

    // auto sccs = g.getSCCv1();
    // for (const auto& scc : sccs)
    // {
    //     printVector(scc);
    // }

    cout << "\n============================================\n" << endl;
}

#endif
