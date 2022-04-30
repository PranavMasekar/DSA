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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        Inorder(root,ans);
        int sum = 0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>= low && ans[i]<=high){
                sum += ans[i];
            }
            if(ans[i]>high) break; 
        }
        return sum;
    }   
};

int main(){
    
    return 0;
}