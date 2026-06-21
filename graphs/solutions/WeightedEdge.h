#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include "Edge.h"

class WeightedEdge : public Edge
{
public:
    WeightedEdge(int from = 0, int to = 0, int weight = 0);

    int weight;

    bool operator>(const WeightedEdge& other) const;
    bool operator<(const WeightedEdge& other) const;
};

#endif
