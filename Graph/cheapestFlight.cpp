#include<bits/stdc++.h>
using namespace std;

// Not solved
const int INF = 1e9+10;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int ks) {
        int distance[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==j) distance[i][j] = 0;
                else distance[i][j] = INF;
            }
        }
        for(auto flight : flights){
            int i = flight[0];
            int j = flight[1];
            int wt = flight[2];
            distance[i][j] = wt;
        }
        for(int k=0;k<ks;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]);
                }
            }
        }
        if(distance[src][dst]==INF) return -1;
        else return distance[src][dst];
    }
};

int main(){
    
    return 0;
}