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
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
    int solution(TreeNode* root , int currentHeight , int maxHeight){
        if (root==NULL) return 0;
        int sum = 0;
        if(currentHeight == maxHeight) sum += root->val;

        return sum + solution(root->left,currentHeight+1,maxHeight) + solution(root->right,currentHeight+1,maxHeight); 
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxHeight = maxDepth(root);
        return solution(root,1,maxHeight);
    }
};

int main(){
    
    return 0;
}