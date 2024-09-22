#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<pair<int,int>>p[N];
int dis[N];
class comp{
    public:
    bool operator()(pair<int,int>p1,pair<int,int>p2){
         return p1.second<p2.second;
    }
};
void dijkstra(int par){
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>q;
    q.push({par,0});
    dis[par]=0;
    while(!q.empty()){
        pair<int,int>pq=q.top();
        q.pop();
        int parent=pq.first;
        int cost=pq.second;

        for(pair<int,int>x:p[parent]){
            int child_node=x.first;
            int child_cost=x.second;
            if(cost+child_cost<dis[child_node]){dis[child_node]=cost+child_cost;q.push({child_node,dis[child_node]});}
        }
    }
}

int main () 
{
    int a,b;
    cin>>a>>b;
    while(b--){
        int x,y,z;
        cin>>x>>y>>z;
        p[x].push_back({y,z});
        p[y].push_back({x,z});
    }
   for(int i=0;i<N;i++)dis[i]=INT_MAX;
   dijkstra(0);

   for(int i=0;i<a;i++){cout<<dis[i]<<" ";}cout<<endl;
    return 0;
}
