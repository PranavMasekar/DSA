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
    bool isValid(TreeNode* root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        else return isValid(root->left) || isValid(root->right);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return root;
        if(isValid(root)){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            return root;
        }
        else return NULL;
    }
};

int main(){
    
    return 0;
}