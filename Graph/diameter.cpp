#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int depth[N];

void DFS(int current,int parent=-1){\
    for(int child : g[current]){
        if(child==parent) continue;
        depth[child] = depth[current] + 1;
        DFS(child,current);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    // Got the deepest node in tree
    DFS(1);
    int max_depth = -1;
    int max_depth_node;
    for(int i=0;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0;
    }
    max_depth = -1;
    // Call DFS for deepest node 
    DFS(max_depth_node);
    for(int i=0;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth = depth[i];
        }
    }
    cout<<max_depth<<endl;
    return 0;
}