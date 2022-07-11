#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&nums,int i,vector<vector<int>> &memo,bool prev_taken){
        if(i>=nums.size()){
            if(prev_taken) return 0;
            else return -1e9;
        };
        if(memo[i][prev_taken]!=-1) return memo[i][prev_taken];
        if(prev_taken){
            return memo[i][prev_taken] = max(0,nums[i] + solve(nums,i+1,memo,true));
        }
        else return memo[i][prev_taken] = max(nums[i] + solve(nums,i+1,memo,true),solve(nums,i+1,memo,false));
    }
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>>memo(nums.size(),vector<int>(2,-1));
        return solve(nums,0,memo,false);
    }
};

int main(){
    
    return 0;
}