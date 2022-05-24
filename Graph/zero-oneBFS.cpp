#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N];
vector<int> level(N,INF);
int n,m;

int BFS(){
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop_front();
        for(auto &child : g[current]){
            int child_value = child.first;
            int child_wt = child.second;
            if(level[current] + child_wt < level[child_value]){
                level[child_value] = level[current] + child_wt;
                if(child_wt==1) q.push_back(child_value);
                else q.push_front(child_value);
            }
        }
    }
    return level[n]==INF ? -1 : level[n];
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        if(v1==v2) continue;
        g[v1].push_back({v2,0});
        g[v2].push_back({v1,1});
    }
    cout<<BFS();
    return 0;
}