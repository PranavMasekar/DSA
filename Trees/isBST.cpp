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
    void Inorder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        Inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>ans[i+1]) return false;
        }
        return true;
    }
};

int main(){
    
    return 0;
}