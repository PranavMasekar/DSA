#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> G;
public:
    int findCenter(vector<vector<int>>& edges) {
        for(vector x : edges){
            int v1 = x[0] , v2 = x[1];
            G[v1].push_back(v2);
            G[v2].push_back(v1);
        }
        for(auto it : G){
            if(it.second.size()==edges.size()){
                return it.first;
            }
        }
    }
};

int main(){
    
    return 0;
}