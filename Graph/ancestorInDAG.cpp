#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
// Not solved 
class Solution {
    int inDegree[N];
    void solution(vector<int> G[],vector<int>& temp,int current){
        for(auto child : G[current]){
            temp.push_back(child);
            solution(G,temp,child);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> G[N];
        for(auto edge:edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back(j);
            inDegree[j]++;
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> temp;
            solution(G,temp,i);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

int main(){
    
    return 0;
}