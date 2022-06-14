#include <bits/stdc++.h>
using namespace std;
const int N = 200;
const int INF = 1e9 + 10;

// Not solved
class Solution {
    int count = 0;
    vector<pair<int, int>> G[N];
    void dijkstra(int source)
    {
        vector<int> distance(N, INF);
        vector<int> visit(N, 0);
        // In this pair first value is distance and second value is node as set is sorted by first value
        set<pair<int, int>> st;
        // Pair<Distance,Node>
        st.insert({0, source});
        distance[source] = 0;
        while (st.size() > 0)
        {
            // Minimum element in set
            auto node = *st.begin();
            int dist = node.first;
            int current = node.second;
            st.erase(st.begin());
            if (visit[current])
                continue;
            visit[current] = 1;
            for (auto child : G[current])
            {
                int child_vertex = child.first;
                int child_wt = child.second;
                if(distance[current] + child_wt == distance[child_vertex]) count++;
                else if (distance[current] + child_wt < distance[child_vertex])
                {
                    count = 0;
                    distance[child_vertex] = distance[current] + child_wt;
                    st.insert({distance[child_vertex], child_vertex});
                }
            }
        }
    }

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        for(auto road : roads){
            int i = road[0];
            int j = road[1];
            int wt = road[2];
            G[i].push_back({j,wt});
            G[j].push_back({i,wt});
        }
        dijkstra(0);
        return count;
    }
};

int main()
{

    return 0;
}