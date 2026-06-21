#include "WeightedEdge.h"

WeightedEdge::WeightedEdge(int from, int to, int weight)
    : Edge(from, to), weight(weight)
{}

bool WeightedEdge::operator>(const WeightedEdge& other) const
{
    return weight > other.weight;
}

bool WeightedEdge::operator<(const WeightedEdge& other) const
{
    return weight < other.weight;
}
