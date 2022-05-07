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
    TreeNode* solution(TreeNode* root,TreeNode* target){
        if(root==NULL) return NULL;
        if(root->val==target->val) return root;
        TreeNode* left = solution(root->left,target);
        if(left!=NULL) return left;
        TreeNode* right = solution(root->right,target);
        return right;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solution(cloned,target);
    }
};

int main(){
    
    return 0;
}