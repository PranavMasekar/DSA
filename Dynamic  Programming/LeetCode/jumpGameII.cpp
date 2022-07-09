#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&nums,int i,int n,vector<int>&memo){
        if(i>=n-1) return 0;
        if(memo[i]!=-1) return memo[i];
        int temp = INT_MAX;
        for(int j = 1; j <= nums[i];j++){
            temp = min(temp,1 + solve(nums,i+j,n,memo));
        }
        return memo[i] = temp;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return solve(nums,0,nums.size(),memo);
    }
};

int main(){
    
    return 0;
}