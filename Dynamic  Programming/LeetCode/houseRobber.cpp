#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &nums,int i,vector<int>&memo){
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i] = max(solve(nums,i-2,memo) + nums[i] , solve(nums,i-1,memo));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return solve(nums,nums.size()-1,memo);
    }
};

int main(){
    
    return 0;
}