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
    int count = 0;
    void PreOrder(TreeNode *root, int maximum) {
        if (root != NULL)
        {
            if(root->val>=maximum) {
                count++;
                maximum = max(maximum,root->val);
            }
            PreOrder(root->left, maximum);
            PreOrder(root->right, maximum);
        }
    }
    int goodNodes(TreeNode* root) {
        PreOrder(root,root->val);
        return count;
    }
};

int main(){
    
    return 0;
}