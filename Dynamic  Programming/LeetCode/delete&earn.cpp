#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &res,int i,vector<int>&memo){
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i] = max(solve(res,i-2,memo) + res[i] , solve(res,i-1,memo));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end()) + 1;
        vector<int> res(n,0);
        vector<int> memo(n,-1);
        for(int i=0;i<nums.size();i++){
            res[nums[i]]+= nums[i];
        }
        return solve(res,res.size()-1,memo);
    }
};
int main(){
    
    return 0;
}