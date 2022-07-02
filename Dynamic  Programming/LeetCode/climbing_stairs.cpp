#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t = cost;
        for(int i=2;i<n;i++){
            t[i] += min(t[i-1],t[i-2]);
        }
        return min(t[n-1],t[n-2]);
    }
};

int main(){
    
    return 0;
}