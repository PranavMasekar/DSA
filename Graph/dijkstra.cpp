#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

// Pair<Node,weight>
vector<pair<int,int>> G[N];
void dijkstra(int source){
    vector<int> distance(N,INF);
    vector<int> visit(N,0);
    // In this pair first value is distance and second value is node as set is sorted by first value
    set<pair<int,int>> st;
    // Pair<Distance,Node>
    st.insert({0,source});
    distance[source] = 0;
    while(st.size()>0){
        // Minimum element in set
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
    for(int i=0;i<5;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        G[x].push_back({y,wt});
    }
    dijkstra(0);
    return 0;
}