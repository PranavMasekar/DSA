#include<bits/stdc++.h>
using namespace std;

// Not solved yet
class Solution {
    bool DFS(vector<int> G[],int current,vector<bool>& visit,int parent){
    bool doesExits = false;
    visit[current] = true;
    for(int child : G[current]){
        if(visit[child] && child==parent) continue;
        if(visit[child]) return true;
        doesExits |=DFS(G,child,visit,current);
    }
    return doesExits;
}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> G[n+1];
        vector<int> ans;
        vector<bool> visit(n+1,false);
        for(vector<int> edge : edges){
            int i = edge[0],j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
            if(DFS(G,1,visit,1)){
                G[i].pop_back();
                G[j].pop_back();
                ans = edge;
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}