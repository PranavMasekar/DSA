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
    void solution(TreeNode* root,int val,TreeNode* parent){
        if(root==NULL) {
            TreeNode* newNode = new TreeNode(val);
            if(val>parent->val) parent->right = newNode;
            else parent->left = newNode;
            return;
        }
        else if(val>root->val) solution(root->right,val,root);
        else solution(root->left,val,root);

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
             TreeNode* newNode = new TreeNode(val);
             return newNode;
        }
        solution(root,val,root);
        return root;
    }
};

int main(){
    
    return 0;
}