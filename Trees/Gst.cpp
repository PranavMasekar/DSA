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
    int calculate(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return root->val +
               calculate(root->left) +
               calculate(root->right);
    }
    void FormGST(TreeNode *root , TreeNode* parent , bool isLeft)
    {
        if (root != NULL)
        {
            root->val += calculate(root->right);
            if(isLeft){
                root->val += parent->val;
            }
            FormGST(root->left,root,true);
            FormGST(root->right,root,false);
        }
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        FormGST(root,root,false);
        return root;
    }
};

int main()
{

    return 0;
}