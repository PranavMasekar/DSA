#include<bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
class Solution {
    vector<int> ans;
    bool dfs(vector<vector<int>> graph,vector<bool> visit,int source){
        visit[source] = true;
        bool temp = true;
        for(auto child : graph[source]){
            if(visit[child]) return false;
            temp  = temp && dfs(graph,visit,child);
        }
        return temp;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n,false);
        for(int i=0;i<n;i++){
            if(dfs(graph,visit,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
    bool dfs(vector<int> G[],vector<bool> visit,int current,int parent){
        visit[current] = true;
        bool doExist = false;
        for(int child : G[current]){
            if(visit[child] && child==parent) continue;
            if(visit[child]) {
                return true;
            }
            doExist |= dfs(G,visit,child,current);
        }
        return doExist;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> G[n];
        vector<int> ans;
        vector<bool> visit(n,false);
        int i = 0;
        for(vector<int> edge : graph){
            G[i] = edge;
            i++;
        }
        for(int i=0;i<n;i++){
            bool val = dfs(G,visit,i,i-1);
            cout<<i<<" "<<val<<endl;
            if(!val){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n,0);
        vector<int> outDegree(n,0);
        vector<bool> visit(n,false);
        int i = 0;
        for(vector<int> edge : graph){
            outDegree[i] = edge.size();
            for(int val : edge){
                inDegree[val]++;
            }
            i++;
        }
        vector<int> diff(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            diff[i] = inDegree[i]-outDegree[i];
            if(diff[i]>0) ans.push_back(i);
            else if (inDegree[i]==0) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    
    return 0;
}