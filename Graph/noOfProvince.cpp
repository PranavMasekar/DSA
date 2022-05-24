#include<bits/stdc++.h>
using namespace std;

// Solved by using adjancency matrix
class Solution {
    void DFS(vector<int> G[],int current,vector<bool>&visit){
        visit[current] = true;
        for(auto child : G[current]){
            if(visit[child])continue;
            DFS(G,child,visit);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> G[n];
        int i = 0;
        for(vector<int> edge : isConnected){
           for(int j=0;j<edge.size();j++){
               if(edge[j]==1)G[i].push_back(j);
           }
           i++;
        }
        vector<bool> visit(n,false);
        int count = 0;
        for(int i=0;i<visit.size();i++){
            if(visit[i]) continue;
            DFS(G,i,visit);
            count++;
        }
        return count;
    }
};

int main(){
    
    return 0;
}