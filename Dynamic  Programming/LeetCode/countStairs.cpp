#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i ,int n,vector<int>&t){
        if(i>=n) return 1;
        if(t[i]!=-1) return t[i];
        return t[i] = solve(i+1,n,t) + solve(i+2,n,t);
    }
public:
    int climbStairs(int n) {
        vector<int> t(n+1,-1);
        return solve(1,n,t);
    }
};

int main(){
    
    return 0;
}