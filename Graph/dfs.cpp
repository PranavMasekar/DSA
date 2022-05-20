#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];

void DFS(int vertex,vector<bool>& visit){
    //Actions on vertex after entering
    cout<<vertex<<endl;
    visit[vertex] = true;
    for(int childs : g[vertex]){
        // Action on child node before visiting child node
        if(visit[childs]) continue;
        DFS(childs,visit);
        // Action on child node after visiting child node
    }
    //Action on vertex before leaving the vertex 
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