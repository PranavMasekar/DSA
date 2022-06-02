#include<bits/stdc++.h>
using namespace std;

// Find the inDegree of each node and compare each node with another 
// if connected -1
class Solution {
    int getMaxIndex(vector<int> degree,int index){
        int val = 0;
        int ans = 0;
        for(int i=0;i<degree.size();i++){
            if(i==index) continue;
            if(degree[i]>val) {
                ans = i;
                val = degree[i];
            }
        }
        return ans;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        vector<int> G[n];
        for(auto edge : roads){
            int i = edge[0] , j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
            degree[i]++;
            degree[j]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = degree[i] + degree[j];
                for(int val : G[i]){
                       if(val==j) {
                           sum -= 1;
                       }
                 }
                 ans = max(ans,sum);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}