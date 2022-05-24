#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int> G[],int current,vector<bool>& visit){
        visit[current] = true;
        for(int child : G[current]){
            if(visit[child]) continue;
            DFS(G,child,visit);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> G[n];
        vector<bool> visit(n,false);
        for(int i=0;i<edges.size();i++){
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]); 
        }
        DFS(G,source,visit);
        return visit[destination];
    }
};

int main(){
    
    return 0;
}