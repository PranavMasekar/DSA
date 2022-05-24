#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> G[1000];
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(auto edge :  trust){
            G[edge[0]].push_back(edge[1]);
        }
        int judge = 0;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(G[i].empty()){
                judge = i;
                count++;
            }
        }
        if(count>1) return -1;
        for(int i=1;i<=n;i++){
            if(i==judge) continue;
            if(find(G[i].begin(),G[i].end(),judge)!=G[i].end()){
                
            }
            else return -1;
        }
        return judge;
    }
};

class Solution {
    vector<int> G[1000];
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n+1,0);
        vector<int> inDegree(n+1,0);
        for(auto edge : trust){
            outDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(outDegree[i]==0 && inDegree[i]==n-1) return i;
        }
        return -1;
    }
};

int main(){
    
    return 0;
}