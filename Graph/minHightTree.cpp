#include<bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
const int INF = 1e5+10;
class Solution {
    int height(vector<vector<int>> G,int source,vector<bool> &visit,int parent,int count){
        int temp = 0;
        visit[source] = true;
        for(int child : G[source]){
            if(child==parent) continue;
            temp = 1 + height(G,child,visit,source,0);
            count = max(count,temp);
        }
        visit[source] = false;
        return count;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        vector<bool> visit(n,false);
        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
        }
        vector<int> temp;
        int minheight = INF;
        for(int i=0;i<n;i++){
            int x = height(G,i,visit,i,0);
            cout<<i<<" "<<x<<endl;
            temp.push_back(x);
            minheight = min(minheight,x);
           for(int i=0;i<n;i++) visit[i] = false;
        }
        cout<<endl;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(temp[i]==minheight) ans.push_back(i);
        }
        return ans;
    }
};



int main(){
    
    return 0;
}