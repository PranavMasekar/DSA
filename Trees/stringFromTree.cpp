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
    void solution(TreeNode* root , string& ans){
        if(root->right==NULL){
            ans += to_string(root->val) + "(";
            solution(root->left,ans);
            ans += ")";
            return;
        }
        ans += to_string(root->val) + "(";
        solution(root->left,ans);
        ans +=")(";
        solution(root->left,ans);
        ans += ")";
    }
    string tree2str(TreeNode *root)
    {
        string ans = "";
        if (root == NULL)
            return "";
        if (root->left == NULL && root->right == NULL)
            return to_string(root->val) + "";
        // solution(root,ans);
        // return ans;
        if (root->right == NULL)
        {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};

int main()
{

    return 0;
}