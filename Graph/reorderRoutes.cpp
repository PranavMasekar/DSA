#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans = 0;
    void solution(vector<pair<int,int>> G[],vector<bool> &visit,int current,int parent){
        visit[current] = true;
        for(auto child : G[current]){
            if(visit[child.first]) continue;
            ans += child.second;
            solution(G,visit,child.first,current);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> G[n];
        vector<bool> visit(n,false);
        for(auto edge :  connections){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back({j,1});
            G[j].push_back({i,0});
        }
        solution(G,visit,0,0);
        return ans;
    }
};

int main(){
    
    return 0;
}