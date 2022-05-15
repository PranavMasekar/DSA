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
    TreeNode* successor(TreeNode* root){
        root = root->right;
        while(root!=NULL && root->left!=NULL) root = root->left;
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key<root->val) root->left = deleteNode(root->left,key);
        else if(key>root->val) root->right = deleteNode(root->right,key);
        else {
            if(root->left==NULL){
                TreeNode* curr = root->right;
                delete(root);
                return curr;
            }
            else if(root->right==NULL){
                TreeNode* curr = root->left;
                delete(root);
                return curr;
            }
            else{
                TreeNode* succ;
                succ = successor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right,succ->val);
            }
            
        }
        return root;
    }
};

int main(){
    
    return 0;
}