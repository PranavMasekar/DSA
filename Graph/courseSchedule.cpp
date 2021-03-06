#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool DFS(vector<int> G[],vector<bool>&visit,int current){
        if(visit[current]) return false;
        if(G[current].empty()) return true;
        visit[current] = true;
        for(auto child : G[current]){
            if(!DFS(G,visit,child)) return false;
        }
        visit[current] = false;
        G[current].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses];
        vector<bool> visit(numCourses,false);
        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            if(i==j) return false;
            G[i].push_back(j);
        }
        if(prerequisites.size()<2) return true;
        for(int i=0;i<numCourses;i++){
            if(!DFS(G,visit,i)) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}