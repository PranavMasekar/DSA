#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;
int val[N][N];
int vis[N][N];
int lev[N][N];
int n,m;

vector<pair<int,int>> movements = {
    {0,1},{0,-1},{1,0},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int bfs(){
    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mx = max(mx,val[i][j]);
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx==val[i][j]) {
                q.push({i,j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        int vx = v.first;
        int vy = v.second;
        q.pop();
        for(auto movement : movements){
            int childx = movement.first + vx;
            int childy = movement.second + vy;
            if(!isValid(childx,childy)) continue;
            if(vis[childx][childy]) continue;
            q.push({childx,childy});
            lev[childx][childy] = lev[vx][vy] + 1;
            vis[childx][childy] = 1;
            ans = max(ans,lev[childx][childy]);
        }
    }
    return ans;
}

void reset(){
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = 0;
                lev[i][j] = INF;
            }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin >>n >>m;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}