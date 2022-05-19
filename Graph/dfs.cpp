#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];

void DFS(int vertex,vector<bool>& visit){
    // Printing the element and marking it as visited
    cout<<vertex<<endl;
    visit[vertex] = true;
    for(int child : g[vertex]){
        // If already visited then skip
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
    DFS(1,visit);
    return 0;
}