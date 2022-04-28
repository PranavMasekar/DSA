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

class Solution{
    public:
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root)  {
        if(root==NULL) return 0;
        int rootDia = maxDepth(root->left) + maxDepth(root->right);
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        return max({rootDia,leftDia,rightDia});
    }
};

int main(){
    
    return 0;
}