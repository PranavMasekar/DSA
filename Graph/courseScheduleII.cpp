#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            G[j].push_back(i);
            indegree[i]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(int child : G[val]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
            result.push_back(val);
        }
        if(result.size()!=numCourses) return {};
        return result;
    }
};

int main(){
    
    return 0;
}