#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
vector<int>v[1005]; 
int lev[1005];
bool ar[1005];
void bfs(int x){
   queue<int>q;
   q.push(x);
   ar[x]=true;
   lev[x]=0;
   while(!q.empty()){
    int par=q.front();
    cout<<par<<" "<<lev[par]<<endl;
    q.pop();
    for(auto kk:v[par]){
          if(!ar[kk]){
            q.push(kk);
            lev[kk]=lev[par]+1;
            ar[kk]=true;
          } 
    }
   }
}

int32_t main () 
{
    int no,edge;
    cin>>no>>edge;
    while(edge--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    int x;
    cin>>x;
    memset(ar,false,sizeof(ar));
    memset(lev,-1,sizeof(lev));
    bfs(x);

    return 0;
}
