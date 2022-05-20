#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];

bool DFS(int current,vector<bool>& visit,int parent){
    // Starting DFS for current
    bool doesExits = false;
    visit[current] = true;
    for(int child : g[current]){
        // Parent cycle check
        if(visit[child] && child==parent) continue;
        // If already visited then
        if(visit[child]) return true;
        doesExits |=DFS(child,visit,current);
    }
    return doesExits;
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
    bool doesExits = false;
    for(int i=1;i<=n;i++){
        if(visit[i]) continue;
        if(DFS(i,visit,i)){
            doesExits = true;
            break;
        }
    }
    cout<<doesExits<<endl;
    return 0;
}