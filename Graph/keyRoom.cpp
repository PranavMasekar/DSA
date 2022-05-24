#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<int> G[],int current,vector<bool>& visit){
        visit[current] = true;
        for(int child : G[current]){
            if(visit[child]) continue;
            DFS(G,child,visit);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int source = 0;
        int n = rooms.size();
        vector<int> G[n];
        int i = 0;
        for(vector<int> edge : rooms){
            for(auto val : edge) {
                if(i==val) continue;
                G[i].push_back(val);
            }
            i++;
        }
        vector<bool> visit(n,false);
        DFS(G,0,visit);
        for(bool val : visit){
            if(val==false) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}