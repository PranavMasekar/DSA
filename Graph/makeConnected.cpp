#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int> G[],vector<bool> &visit,int current){
        visit[current] = true;
        for(auto child : G[current]){
            if(visit[child]) continue;
            DFS(G,visit,child);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        if(totalEdges<n-1) return -1;
        vector<int> G[n];
        vector<bool> visit(n,false);
        for(auto edge : connections){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
        }
        int count = 0;
        for(int i = 0;i<visit.size();i++){
            if(visit[i]) continue;
            DFS(G,visit,i);
            count++;
        }
        return count;
    }
};

int main(){
    
    return 0;
}