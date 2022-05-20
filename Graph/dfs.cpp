#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];

void DFS(int current,vector<bool>& visit){
    //Actions on current after entering
    cout<<current<<endl;
    visit[current] = true;
    for(int child : g[current]){
        // Action on child node before visiting child node
        if(visit[child]) continue;
        DFS(child,visit);
        // Action on child node after visiting child node
    }
    //Action on current before leaving the current 
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
    DFS(1,visit);
    return 0;
}