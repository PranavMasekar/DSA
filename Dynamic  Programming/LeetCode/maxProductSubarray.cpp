#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(),nums.end());
        int currMin = 1 , currMax = 1;

        for(int x : nums){
            if(x==0){
                currMin = 1;
                currMax = 1;
            }
            int temp = currMax;
            currMax = max({currMax * x , currMin * x , x});
            currMin  = min({currMin * x , temp * x , x});
            res = max({res,currMax,currMin});
        }
        return res;
    }
};

int main(){
    
    return 0;
}