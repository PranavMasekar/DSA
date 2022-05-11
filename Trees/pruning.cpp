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
// Incomplete
class Solution {
    TreeNode* newRoot;
    TreeNode* temp;
    bool isValid(TreeNode* root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        else return isValid(root->left) || isValid(root->right);
    }
    void solve(TreeNode* root,TreeNode* myRoot){
        if(root==NULL) return;
        if(root->left!=NULL && !isValid(root->left)){
            myRoot->left = NULL;
        }
        else {
            TreeNode* newNode = new TreeNode(root->val);
            myRoot->left = newNode;
        }
       
        if(root->right!=NULL && !isValid(root->right)){
            myRoot->right = NULL;
        }
        else {
            TreeNode* newNode = new TreeNode(root->val);
            myRoot->right = newNode;
        }
        solve(root->left,myRoot->left);
        solve(root->right,myRoot->right);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode* newNode = new TreeNode(root->val);
        newRoot = newNode;
        temp = root;
        solve(root,temp);
        return newRoot;
    }
};

int main(){
    
    return 0;
}