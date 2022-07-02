#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, vector<int> &t){
        if(n<2) return n;
        if(n==2) return 1;
        if(t[n]!=-1) return t[n];
        return t[n] = solve(n-1,t) + solve(n-2,t) + solve(n-3,t);
    }
public:
    int tribonacci(int n) {
        vector<int> t(n+1,-1);
        return solve(n,t);
    }
};

int main(){
    
    return 0;
}