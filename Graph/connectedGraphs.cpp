#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];

void DFS(int current,vector<bool>& visit){
    visit[current] = true;
    for(int child : g[current]){
        if(visit[child]) continue;
        DFS(child,visit);
    }
}


int main(){
    vector<bool> visit = {false};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(visit[i]) continue;
        DFS(i,visit);
        count++;
    }
    cout<<count<<endl;
    return 0;
}