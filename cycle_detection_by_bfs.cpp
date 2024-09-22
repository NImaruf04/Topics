#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
const int n = 1e5 + 5;
vector<int> v[n];
bool vis[n];
int parent[n];
bool tr = false;
void bfs(int s)
{

    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (vis[child] == true && parent[par] != child)
            {
                tr = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}

int32_t main()
{
    int a, b;
    cin >> a >> b;
    while (b--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < a; i++)
    {
        if (!vis[i])
            bfs(i);
    }
    if (tr)
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;
    return 0;
}
