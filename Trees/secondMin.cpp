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
    void Preorder(TreeNode *root, set<int> &ans)
    {
        if (root != NULL)
        {
            ans.insert(root->val);
            Preorder(root->left, ans);
            Preorder(root->right, ans);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        Preorder(root,ans);
        if(ans.size()==1) return -1;
        else return *next(ans.begin(),1);
    }
};

int main(){
    
    return 0;
}


