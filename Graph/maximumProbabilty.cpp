#include<bits/stdc++.h>
using namespace std;

class Solution {;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> G[n];
        vector<double> probability(n,0.0);
        priority_queue<pair<double,int>> st;
        probability[start] = 1.0;
        st.push({1.0,start});
        int k = 0;
        for(auto edge :  edges){
            int i = edge[0];
            int j = edge[1];
            G[i].push_back({j,succProb[k]});
            G[j].push_back({i,succProb[k]});
            k++;
        }
        while(st.size()>0){
            auto node = st.top();
            st.pop();
            int current = node.second;
            double dist = node.first;
            if(current==end) return dist;
            if(dist<probability[current]) continue;
            for(auto child: G[current]){
                int child_vertex = child.first;
                double child_wt = child.second;
                if(probability[current] * child_wt > probability[child_vertex]){
                   probability[child_vertex] = probability[current] * child_wt ;
                   st.push({probability[child_vertex],child_vertex}); 
                }
            }
        }
        return 0.0;
    }
};

int main(){
    
    return 0;
}