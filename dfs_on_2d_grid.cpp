#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;
char cr[20][20];
bool vis[20][20];
vector<pair<int,int>>p={{0,1},{0,-1},{-1,0},{1,0}};
int a,b;
bool valid(int ci,int mi){
    if(ci<0||ci>=a||mi<0||mi>=b){
        return false;
    }
    return true;
}
void dfs(int x,int y){
       cout<<x<<" "<<y<<endl;;
       vis[x][y]=true;
       for(int i=0;i<4;i++){
        int ti=p[i].first+x;
        int pi=p[i].second+y;
        if(valid(ti,pi)&&vis[ti][pi]==false){dfs(ti,pi);}
       
       }
}
int32_t main () 
{
   
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>cr[i][j];
        }
    }
    dfs(1,1);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<cr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
