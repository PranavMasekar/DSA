#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i,int j,int m,int n,vector<vector<int>>&t,vector<vector<int>>& obstacleGrid){
        if(i>=m || j>=n || obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(t[i][j]!=-1) return t[i][j];
        return t[i][j] = solve(i+1,j,m,n,t,obstacleGrid) + solve(i,j+1,m,n,t,obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,t,obstacleGrid);
    }   
};

int main(){
    
    return 0;
}