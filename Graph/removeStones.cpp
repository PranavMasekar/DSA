#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int>G[],int current,vector<bool>& visit,int& count){
        visit[current] = true;
        for(int child : G[current]){
            if(visit[child]) continue;
            count++;
            DFS(G,child,visit,count);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> G[n];
        vector<bool> visit(n,false);
        for(auto edge : stones){
            int i = edge[0];
            int j = edge[1];
            if(i==j) continue;
            G[i].push_back(j);
            G[j].push_back(i);
        }
        int count;
        int ans = 0;
        for(int i=0;i<stones.size();i++){
            if(visit[i])continue;
            count = 0;
            DFS(G,i,visit,count);
            ans += count;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}