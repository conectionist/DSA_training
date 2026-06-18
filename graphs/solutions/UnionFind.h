#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

using std::vector;

class UnionFind
{
public:
    UnionFind(int n);

    bool unite(int x, int y);
    int find(int x);

private:
    vector<int> parent;
    vector<int> rank;
};

#endif
