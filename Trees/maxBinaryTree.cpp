#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* solution(vector<int>& nums,int low,int high){
        if(low>high) return NULL;
        if(low==high){
            TreeNode* newNode = new TreeNode(nums[low]);
            return newNode;
        }
        int maxElement = -1 , maxIndex = -1;
        for(int i=low;i<=high;i++){
            if(maxElement<nums[i]){
                maxElement = max(maxElement,nums[i]);
                maxIndex = i;
            }
        }
        TreeNode* newNode = new TreeNode(maxElement);

        newNode->left = solution(nums,low,maxIndex-1);
        newNode->right = solution(nums,maxIndex+1,high);
        return newNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solution(nums,0,nums.size()-1);
    }

};

int main(){
    
    return 0;
}