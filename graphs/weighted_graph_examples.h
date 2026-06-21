#ifndef WEIGHTED_GRAPH_EXAMPLES_H
#define WEIGHTED_GRAPH_EXAMPLES_H

#include "graph_tests.h"

#include <iostream>

using std::cout, std::endl;

inline void runPractice()
{
    cout << "\n============================================\n" << endl;

    // ----------------------------------------------------------
    // Weighted graph examples
    // Uncomment the one you want to run.
    // ----------------------------------------------------------

    vector<vector<WeightedEdge>> weightedAdj =
    {
        {WeightedEdge(0, 1, 4), WeightedEdge(0, 2, 8)},
        {WeightedEdge(1, 0, 4), WeightedEdge(1, 2, 3), WeightedEdge(1, 4, 6)},
        {WeightedEdge(2, 0, 8), WeightedEdge(2, 1, 3), WeightedEdge(2, 3, 2)},
        {WeightedEdge(3, 2, 2), WeightedEdge(3, 4, 10)},
        {WeightedEdge(4, 1, 6), WeightedEdge(4, 3, 10)}
    };

    WeightedGraph weightedGraph(weightedAdj);

    WeightedGraph wg2(5);
    wg2.addEdge(0,1,4);
    wg2.addEdge(0,2,8);
    wg2.addEdge(1,0,4);
    wg2.addEdge(1,2,3);
    wg2.addEdge(1,4,6);
    wg2.addEdge(2,0,8);
    wg2.addEdge(2,1,3);
    wg2.addEdge(2,3,2);
    wg2.addEdge(3,2,2);
    wg2.addEdge(3,4,10);
    wg2.addEdge(4,1,6);
    wg2.addEdge(4,3,10);

    WeightedGraph wg3(8);
    wg3.addEdge(0,1,20);
    wg3.addEdge(0,3,80);
    wg3.addEdge(0,6,90);
    wg3.addEdge(1,5,10);
    wg3.addEdge(2,3,10);
    wg3.addEdge(2,5,50);
    wg3.addEdge(2,7,20);
    wg3.addEdge(3,2,10);
    wg3.addEdge(3,6,20);
    wg3.addEdge(4,1,50);
    wg3.addEdge(4,6,30);
    wg3.addEdge(5,2,10);
    wg3.addEdge(5,3,40);
    wg3.addEdge(6,0,20);
    
    WeightedGraph wg4(4);
    wg4.addEdge(0,1,4);
    wg4.addEdge(0,3,5);
    wg4.addEdge(1,2,3);
    wg4.addEdge(3,2,-8);
    
    // bellman ford - the good youtube video
    WeightedGraph wg5(6);
    wg5.addEdge(0,1,10);
    wg5.addEdge(0,5,8);
    wg5.addEdge(1,3,2);
    wg5.addEdge(2,1,1);
    wg5.addEdge(3,2,-2);
    wg5.addEdge(4,1,-4);
    wg5.addEdge(4,3,-1);
    wg5.addEdge(5,4,1);

    WeightedGraph wg6(5);
    wg6.addEdge(0,1,5);
    wg6.addEdge(1,2,1);
    wg6.addEdge(1,3,2);
    wg6.addEdge(2,4,1);
    wg6.addEdge(4,3,-1);
    
    WeightedGraph wg7(6);
    wg7.addEdge(0,1,4);
    wg7.addEdge(0,2,6);
    wg7.addEdge(1,3,3);
    wg7.addEdge(2,4,-1);
    wg7.addEdge(2,5,5);
    wg7.addEdge(3,5,-2);
    wg7.addEdge(4,1,-2);
    wg7.addEdge(4,3,2);
    wg7.addEdge(5,4,3);
    
    // with a negative cycle
    WeightedGraph wg8(6);
    wg8.addEdge(0,1,10);
    wg8.addEdge(0,5,8);
    wg8.addEdge(1,3,2);
    wg8.addEdge(2,1,1);
    wg8.addEdge(3,2,-2);
    wg8.addEdge(4,1,-4);
    wg8.addEdge(3,4,-1);
    wg8.addEdge(5,4,1);

    WeightedGraph wg9(7);
    wg9.addEdge(0,1,2,true);
    wg9.addEdge(0,2,3,true);
    wg9.addEdge(0,3,3,true);
    wg9.addEdge(1,2,4,true);
    wg9.addEdge(1,4,3,true);
    wg9.addEdge(2,3,5,true);
    wg9.addEdge(2,4,1,true);
    wg9.addEdge(2,5,6,true);
    wg9.addEdge(3,5,7,true);
    wg9.addEdge(4,5,8,true);
    wg9.addEdge(5,6,9,true);
    
    auto& wg = wg9;                        

    // // dijkstra
    // int from = 0;
    // auto shortestPaths = wg.dijkstra(from);

    // cout << "Dijkstra" << endl;
    // cout << "Cel mai scurt drum de la " << from << " la " << endl;
    // for(int i = 0 ; i < shortestPaths.size() ; i++)
    //     if(i != from)
    //     {
    //         cout << "- " << i;
    //         if(shortestPaths[i].cost == INT_MAX)
    //             cout << " - NU EXISTA" << endl;
    //         else
    //             cout << " costa " << shortestPaths[i].cost << ". Drumul complet: " << getEntirePath(shortestPaths, from, i) << endl;
    //     }

    // try
    // {
    //     int from = 0;
    //     auto shortestPaths = wg.bellmanFord(from);

    //     cout << "Bellman Ford" << endl;
    //     cout << "Cel mai scurt drum de la " << from << " la " << endl;
    //     for(int i = 0 ; i < shortestPaths.size() ; i++)
    //         if(i != from)
    //         {
    //             cout << "- " << i;
    //             if(shortestPaths[i].cost == INT_MAX)
    //                 cout << " - NU EXISTA" << endl;
    //             else
    //                 cout << " costa " << shortestPaths[i].cost << ". Drumul complet: " << getEntirePath(shortestPaths, from, i) << endl;
    //         }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // auto allPaths = wg.floydWarshall();
    // int n = allPaths.size();

    // cout << "\nFloyd Warshall\n";
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout << "Drumul de la " << i << " la " << endl;
    //     for(int j = 0 ; j < n ; j++)
    //     {
    //         if(i == j)
    //             continue;
            
    //         cout << "- " << j;
    //         if(allPaths[i][j] == INT_MAX)
    //             cout << " nu exista";
    //         else
    //             cout << " costa " << allPaths[i][j];
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    //cout << "Prim:"    << endl << wg.prim().toString()    << endl;
    cout << "Kruskal:" << endl << wg.kruskal().toString() << endl;
    //cout << "Boruvka:" << endl << wg.borukva().toString() << endl; 

    cout << "\n============================================\n" << endl;
}

#endif
