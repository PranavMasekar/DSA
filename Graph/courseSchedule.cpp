#include<bits/stdc++.h>
using namespace std;

// Not Solved
class Solution {
    bool CycleDetection(vector<int> G[],int current,vector<bool> visit){
    visit[current] = true;
    bool doesExits = false;
    for(int child : G[current]){
        if(visit[child]) return true;
        doesExits |=CycleDetection(G,child,visit);
    }
    return doesExits;
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
            if(CycleDetection(G,i,visit)){
                return false;
            }
            for(int i=0;i<numCourses;i++) visit[i] = false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}