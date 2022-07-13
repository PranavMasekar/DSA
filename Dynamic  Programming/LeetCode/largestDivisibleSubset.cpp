#include<bits/stdc++.h>
using namespace std;

//! Not Completed

// Recursive Approach TLE
class Solution {
    vector<int> res;
    void solve(int i,vector<int>&nums,vector<int> &ans,int prev){
        if(i==nums.size()){
            if(ans.size()>res.size()) res = ans;
            return;
        }
        if(prev==-1 || nums[i]%nums[prev]==0){
            ans.push_back(nums[i]);
            solve(i+1,nums,ans,i);
            ans.pop_back();
            solve(i+1,nums,ans,prev);
        }
        else solve(i+1,nums,ans,prev);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,nums,temp,-1);
        return res;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]) LIS[i] = max(LIS[i],1+LIS[j]);
            }
        }
    }
};

int main(){
    
    return 0;
}