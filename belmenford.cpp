#include<bits/stdc++.h>
using namespace std;
class edgelist{
    public:
    int u,v,c;
    edgelist(int u,int v,int c){
        this->u=u;
        this->v=v;
        this->c=c;

    }
};

int main () 
{
    int a,b;
    cin>>a>>b;
    vector<edgelist>ed;
    const int N=1e5;
    int dis[N];
    while(b--){
        int u,v,c;
        cin>>u>>v>>c;
        ed.push_back(edgelist(u,v,c));

    }
    for(int i=1;i<a;i++)dis[i]=INT_MAX;
    dis[0]=0;
    for(int i=0;i<a;i++){
        for(edgelist edge:ed){
            if(dis[edge.u]<INT_MAX && dis[edge.u]+edge.c <dis[edge.v])dis[edge.v]=dis[edge.u]+edge.c;
        }
    }
    bool tr=false;
    for(edgelist edge:ed){
            if(dis[edge.u]<INT_MAX && dis[edge.u]+edge.c <dis[edge.v])tr=true;
        }
        if(tr)cout<<" cycle detected"<<endl;
        else {
for(int i=0;i<a;i++)cout<<i<<"->"<<dis[i]<<endl;}
    
    return 0;
}
