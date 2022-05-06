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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        vector<int> two;
        Inorder(root1,one);
        Inorder(root2,two);
        vector<int> ans;
        merge(one.begin(),one.end(),two.begin(),two.end(),back_inserter(ans));
        return ans;
    }
};

int main(){
    
    return 0;
}