#include "UnionFind.h"

UnionFind::UnionFind(int n) : parent(n), rank(n, 0)
{
    for(int i = 0; i < n; ++i)
        parent[i] = i;
}

bool UnionFind::unite(int x, int y)
{
    (void)x;
    (void)y;
    return false;
}

int UnionFind::find(int x)
{
    return x;
}
