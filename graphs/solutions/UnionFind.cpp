#include "UnionFind.h"

UnionFind::UnionFind(int n) : parent(n), rank(n, 0)
{
    for(int i = 0 ; i < n ; i++)
        parent[i] = i;
}

bool UnionFind::unite(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if(root_x == root_y)
        return false;
        
    if(rank[root_x] > rank[root_y])
        parent[root_y] = root_x;
    else if(rank[root_x] < rank[root_y])
        parent[root_x] = root_y;
    else
    {
        parent[root_y] = root_x;
        rank[root_x]++;
    }

    return true;
}

int UnionFind::find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}
