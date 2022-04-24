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

class Solution
{
public:
    void Inorder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        Inorder(root, ans);
        return ans;
    }

    void PreOrder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            ans.push_back(root->val);
            PreOrder(root->left, ans);
            PreOrder(root->right, ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PreOrder(root,ans);
        return ans;
    }

    void PostOrder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            PostOrder(root->left, ans);
            PostOrder(root->right, ans);
            ans.push_back(root->val);
        }
    }    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostOrder(root,ans);
        return ans;
    }
};

int main()
{
    return 0;
}