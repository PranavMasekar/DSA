#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int> G[],vector<bool>&visit,int current,set<int>&ans){
        if(visit[current]) return;
        if(G[current].empty()){
            ans.insert(current);
            return;
        }
        visit[current] = true;
        for(auto child : G[current]){
            DFS(G,visit,child,ans);
        }
        visit[current] = false;
        G[current].clear();
        ans.insert(current);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses];
        vector<bool> visit(numCourses,false);
        set<int> ans;
        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            if(i==j) return vector<int>(0);
            G[i].push_back(j);
        }
        for(int i=0;i<numCourses;i++){
            DFS(G,visit,i,ans);
        }
        vector<int> res(ans.begin(),ans.end());
        return res;
    }
};

int main(){
    
    return 0;
}