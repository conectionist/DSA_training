#include "UnionFind.h"

UnionFind::UnionFind(int n) : parent(n), rank(n, 0)
{

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
