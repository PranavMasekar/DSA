#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int> G[],int current, int destination, vector<bool>&visit,vector<vector<int>>&ans,vector<int> path){
        path.push_back(current);
        if(current==destination) {
            ans.push_back(path);
            return;
        }
        for(int child : G[current]){
            DFS(G,child,destination,visit,ans,path);
        } 
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int n = graph.size();
        int destination = n - 1;
        vector<int> G[n + 1];
        int i = 0;
        for(vector<int> edge : graph){
            for(auto val : edge) G[i].push_back(val);
            i++;
        }
        vector<bool> visit(n + 1,false);
        vector<vector<int>> ans;
        vector<int> path;
        DFS(G,source,destination,visit,ans,path);
        return ans;
    }
};

int main(){
    
    return 0;
}