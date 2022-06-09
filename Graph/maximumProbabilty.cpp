#include<bits/stdc++.h>
using namespace std;

// Not Solved
class Solution {
    void DFS(vector<vector<int>> G,int current, int destination, vector<bool>&visit,vector<vector<int>>&ans,vector<int> path){
        path.push_back(current);
        if(current==destination) {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<G[current].size();i++){
            if(G[current][i]!=0){
                DFS(G,G[current][i],destination,visit,ans,path);
            }
        }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<int>> G(n,vector<int>(n,0));
        vector<bool> visit(n,false);
        int k = 0;
        for(auto edge :  edges){
            int i = edge[0];
            int j = edge[1];
            G[i][j] = succProb[k];
            G[j][i] = succProb[k];
            k++;
        }
        vector<vector<int>> ans;
        vector<int> path;
        DFS(G,start,end,visit,ans,path);
        if(ans.size()==0) return 0;
        double maxprob = 0;
        for(auto vec : ans){
            double tempMax = 1;
            for(int i=1;i<=vec.size();i++){
                tempMax *= G[i-1][i];
            }
            maxprob = max(maxprob,tempMax);
        }
        return maxprob;
    }
};

int main(){
    
    return 0;
}