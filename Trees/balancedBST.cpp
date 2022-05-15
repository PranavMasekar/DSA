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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        if(abs(maxDepth(root->left) - maxDepth(root->right))>1) return false;
        else{
            return isBalanced(root->left) && isBalanced(root->right);
        }

    }
};

int main(){
    
    return 0;
}