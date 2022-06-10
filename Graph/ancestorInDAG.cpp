#include<bits/stdc++.h>
using namespace std;
const int N = 1001;

class Solution {
    void solution(vector<int> G[],vector<vector<int>>& ans,int current,vector<bool> &visit,int previous){
        visit[current] = true;
        if(current!=previous) ans[current].push_back(previous);
        for(auto child : G[current]){
            if(visit[child]) continue;
            solution(G,ans,child,visit,previous);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> G[n];
        for(auto edge:edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back(j);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<bool> visit(n,false);
            solution(G,ans,i,visit,i);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}