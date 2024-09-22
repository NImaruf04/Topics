#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;

const int N=1e5+5;
vector<int>v[N];
bool vis[N];
void dfs(int src){
    cout<<src<<" ";
    vis[src]=true;
    for(int i:v[src]){
        if(!vis[i]){dfs(i);}
    }

}
int32_t main () 
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;cin>>k;
    memset(vis,false,sizeof(vis));
    dfs(k);
    return 0;
}
