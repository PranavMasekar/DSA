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
    void Inorder(TreeNode *root, vector<int> &ans) {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }

    TreeNode* Create(TreeNode* root,vector<int> &ans, int index){
        if(ans.size()==index){
            return NULL;
        }
        TreeNode * newNode =new TreeNode(ans[index]);
        index++;
        newNode->right = Create(root,ans,index);
        return newNode;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        Inorder(root,ans);
        return Create(root,ans,0);
    }
};

int main(){
    
    return 0;
}