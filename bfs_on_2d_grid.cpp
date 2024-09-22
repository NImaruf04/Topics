#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
char cr[20][20];
bool vis[20][20];
int dis[20][20];
vector<pair<int,int>>p={{0,1},{0,-1},{-1,0},{1,0}};
int a,b;
bool valid(int ci,int mi){
    if(ci<0||ci>=a||mi<0||mi>=b){
        return false;
    }
    return true;
}
void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    dis[x][y]=0;
    while(!q.empty()){
        pair<int,int>par=q.front();
        q.pop();
        cout<<par.first<<" "<<par.second<<endl;
         for(int i=0;i<4;i++){
        int ti=p[i].first+par.first;
        int pi=p[i].second+par.second;
        if(valid(ti,pi)&&vis[ti][pi]==false){
            q.push({ti,pi});
            vis[ti][pi]=true;
            dis[ti][pi]=dis[par.first][par.second]+1;
       
       }

    }
}}
int32_t main () 
{
   
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>cr[i][j];
        }
    }
    int sri,srj;
    cin>>sri>>srj;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));

    bfs(sri,srj);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<cr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<dis[2][3];
    return 0;
}
