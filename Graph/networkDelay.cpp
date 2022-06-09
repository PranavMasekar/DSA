#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int INF = 1e9+10;
class Solution {
    
    void dijkstra(vector<pair<int,int>> G[],vector<int>&visit,int source,vector<int>& distance){
        set<pair<int,int>> st;
        st.insert({0,source});
        distance[source] = 0;
        while(st.size()>0){
            auto node = *st.begin();
            int dist = node.first;
            int current = node.second;
            st.erase(st.begin());
            if(visit[current]) continue;
            visit[current] = 1;
            for(auto child : G[current]){
                int child_vertex = child.first;
                int child_wt = child.second;
                if(distance[current] + child_wt < distance[child_vertex]){
                    distance[child_vertex] = distance[current] + child_wt ;
                    st.insert({distance[child_vertex],child_vertex});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(N,INF);
        vector<int> visit(N,0);
        vector<pair<int,int>> G[N];
        for(auto edge : times){
            int i = edge[0];
            int j = edge[1];
            int wt = edge[2];
            G[i].push_back({j,wt});
        }
        dijkstra(G,visit,k,distance);
        int ans = -1;
        for(int i=0;i<n;i++){
            if(distance[i]==INF) return -1;
            ans = max(ans,distance[i]);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}