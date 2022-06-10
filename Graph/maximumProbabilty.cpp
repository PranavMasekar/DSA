#include<bits/stdc++.h>
using namespace std;

class Solution {;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> G[n];
        vector<double> probability(n,0.0);
        vector<int> visit(n,0);
        set<pair<double,int>> st;
        int k = 0;
        for(auto edge :  edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back({j,succProb[k]});
            G[j].push_back({i,succProb[k]});
            k++;
        }
        st.insert({1,start});
        probability[start] = 1.0;
        while(st.size()>0){
            auto node = *st.begin();
            st.erase(st.begin());
            int current = node.second;
            double dist = node.first;
            if(visit[current]) continue;
            visit[current] = 1;
            if(current==end) return dist;
            for(auto child: G[current]){
                int child_vertex = child.first;
                double child_wt = child.second;
                if(probability[current] * child_wt > probability[child_vertex]){
                   probability[child_vertex] = probability[current] * child_wt ;
                   st.insert({probability[child_vertex],child_vertex}); 
                }
            }
        }
        return 0.0;
    }
};

int main(){
    
    return 0;
}