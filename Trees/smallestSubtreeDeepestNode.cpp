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
    TreeNode* child;
    TreeNode* parent;
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
    void solution(TreeNode* root , int currentHeight , int maxHeight){
        if (root==NULL) return ;
        if(currentHeight == maxHeight) child = root;
        if(root->left!=NULL || root->right!=NULL){
            if(currentHeight +1 == maxHeight) parent = root;
        }
        solution(root->left,currentHeight+1,maxHeight);
        solution(root->right,currentHeight+1,maxHeight); 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root;
        int height = maxDepth(root);
        solution(root,1,height);
        if(parent->left!=NULL && parent->right!=NULL) return parent;
        else return child;
    }
};

int main(){
    
    return 0;
}