#include<bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
using namespace std;

int32_t main () 
{   int n,e;
     cin>>n>>e;
    int ar[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ar[i][j]=INT_MAX;
            if(i==j)ar[i][j]=0;
        }
    }
    while (e--){
        int x,y,z;
        cin>>x,y,z;
        ar[x][y]=z;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              if( ar[i][j]> ar[i][k]+ar[k][j])ar[i][j]= ar[i][k]+ar[k][j];
            }
        }
    }
    return 0;
}
