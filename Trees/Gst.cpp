#include <bits/stdc++.h>
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

// INCOMPLETE

class Solution
{
public:
    map<int,int> ans;
    int totalCost(TreeNode* root){
        if(root==NULL) return 0;
        else return root->val + totalCost(root->left) + totalCost(root->right);
    }
    void Inorder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }
    void form(TreeNode* root){
        if(root!=NULL){
            form(root->left);
            root->val = ans[root->val];
            form(root->right);
        }
    }
    TreeNode *bstToGst(TreeNode *root) {
        int sum = totalCost(root);
        vector<int> values;
        Inorder(root,values);
        for(int i=0;i<values.size();i++){
            ans[values[i]] = sum;
            sum -= values[i];
        }
        form(root);
        return root;
    }
};

int main()
{

    return 0;
}