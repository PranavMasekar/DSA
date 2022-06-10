#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n<=0) return ans;
        if(n==1) {
            ans.push_back(0);
            return ans;
        }
        vector<vector<int>> G(n);
        vector<int> degree(n);
        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
            degree[i]++;
            degree[j]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }
        while(n>2){
            int size = q.size();
            n -= size;
            while(size--){
                int current = q.front();
                q.pop();
                for(auto child : G[current]){
                    degree[child]--;
                    if(degree[child]==1) q.push(child);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};



int main(){
    
    return 0;
}