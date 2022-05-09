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
    int ans = 0;
    void findInSubTree(TreeNode* root,int& small,int& large){
        if(root==NULL) return;
        findInSubTree(root->left,small,large);
        small = min(small,root->val);
        large = max(large,root->val);
        findInSubTree(root->right,small,large);
    }
    void solve(TreeNode* root){
        if(root==NULL) return;
        int LeftSmall = root->val;
        int LeftLarge = root->val;
        int RightLarge = root->val;
        int RightSmall = root->val;
        findInSubTree(root->left , LeftSmall,LeftLarge);
        findInSubTree(root->right , RightSmall,RightLarge);
        int leftDiff1 = abs(root->val - max(LeftSmall,LeftLarge));
        int leftDiff2 = abs(root->val - min(LeftSmall,LeftLarge));
        int rightDiff1 = abs(root->val - max(RightSmall,RightLarge));
        int rightDiff2 = abs(root->val - min(RightSmall,RightLarge));
        int leftDiff = max(leftDiff1,leftDiff2);
        int rightDiff = max(rightDiff1,rightDiff2);
        ans = max({leftDiff,rightDiff,ans});
        solve(root->left);
        solve(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};

int main(){
    
    return 0;
}