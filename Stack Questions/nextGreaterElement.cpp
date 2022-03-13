#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nextBig(vector<int> arr , int index , int value){
        int max = -1;
        for(int i= index;i<arr.size();i++){
            if(arr[i]>value){
                max = arr[i];
                break;
            }
        }
        return max;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nextBig(nums2 , j , nums1[i]));
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}