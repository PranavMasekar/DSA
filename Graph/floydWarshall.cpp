#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
const int N = 510;


int main(){
    int distance[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) distance[i][j] = 0;
            else distance[i][j] = INF;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        distance[x][y] = wt;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(distance[i][j]==INF) cout<<"I ";
            else cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}