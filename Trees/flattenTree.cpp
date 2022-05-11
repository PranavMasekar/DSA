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
    TreeNode* myroot;
    TreeNode* temp;
    void solution(TreeNode* root){
        if(root!=NULL){
            TreeNode* newNode = new TreeNode(root->val);
            temp->right = newNode;
            temp = temp->right;
            solution(root->left);
            solution(root->right);
        }
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* newNode = new TreeNode(root->val);
        myroot = newNode;
        temp = myroot;
        solution(root);
        root = myroot;
    }
};

int main(){
    
    return 0;
}