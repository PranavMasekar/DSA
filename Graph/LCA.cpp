#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int par[N];

void DFS(int current,int parent=-1){
    par[current] = parent;
    for(int child : g[current]){
        if(child==parent) continue;
        DFS(child,current);
    }
}

vector<int> path(int current){
    vector<int> ans;
    while(current!=-1){
        ans.push_back(current);
        current = par[current];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    DFS(1);
    int x,y;
    cin>>x>>y;
    vector<int> x_path = path(x);
    vector<int> y_path = path(y);
    int minLength = min(x_path.size(),y_path.size());
    int LCA = -1;
    for(int i=0;i<minLength;i++){
        if(x_path[i]==y_path[i]){
            LCA = x_path[i];
        }
        else break;
    }
    cout<<LCA<<endl;
    return 0;
}