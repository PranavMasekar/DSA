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
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> memo1(nums.size(),-1);
        vector<int> memo2(nums.size(),-1);
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(solve(v1,v1.size()-1,memo1),solve(v2,v2.size()-1,memo2));
    }
};

int main(){
    
    return 0;
}