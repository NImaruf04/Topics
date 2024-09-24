#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
// first declare the size of parent array
const int N = 1e5;
// then declare the parent array
int parent[N];
// declare the size array of group
int dsu_size[N];

// declare the array of leaders level/rank
int dsu_level[N];
// then declare implemantation function
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        dsu_size[i] = 1;
        dsu_level[i] = 0;
    }
}
// then run the parent find function
int find(int node)
{
    if (parent[node] == -1)
        return node;
    // path compression logic
    return parent[node] = find(parent[node]); // it at the same time stores the value in parent array and returns the value of parent array
}
// dsu Union function
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    parent[leader1] = leader2;
}
// dsu union by size
void dsu_union_by_size(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (dsu_size[leader1] >= dsu_size[leader2])
    {
        parent[leader2] = leader1;
        dsu_size[leader1] += dsu_size[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        dsu_size[leader2] += dsu_size[leader1];
    }
}

// dsu union by level/rank
void dsu_union_by_size(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (dsu_level[leader1] > dsu_level[leader2])
    {
        parent[leader2] = leader1;
    }
    else if (dsu_level[leader1] < dsu_level[leader2])
    {
        parent[leader1] = leader2;
    }
    else
    {
        parent[leader2] = leader1;
        dsu_level[leader1]++;
    }
}
int32_t main()
{
    dsu_initialize(7);
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    cout << find(1) << " " << find(4) << endl;

    return 0;
}
