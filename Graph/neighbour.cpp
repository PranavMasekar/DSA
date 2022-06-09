#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int INF = 1e9+10;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int distance[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) distance[i][j] = 0;
                else distance[i][j] = INF;
            }
        }
        for(auto vec : edges){
            int i = vec[0];
            int j = vec[1];
            int wt = vec[2];
            distance[i][j] = wt;
            distance[j][i] = wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]);
                }
            }
        }
        vector<int> ans(n,0);
        int min = INF;
        int res = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(distance[i][j]<=distanceThreshold){
                    ans[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]<=min){
                min = ans[i];
                res = i;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}