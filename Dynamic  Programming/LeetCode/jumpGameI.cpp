#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>&nums,int i,int n,vector<int>&memo){
        if(i>=n-1) return true;
        if(memo[i]!=-1){
            if(memo[i]==1) return true;
            else return false;
        }
        for(int j = 1; j <= nums[i];j++){
            if(solve(nums,i+j,n,memo)==true) {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return solve(nums,0,nums.size(),memo);
    }
}; 
int main(){
    
    return 0;
}