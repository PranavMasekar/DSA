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
    void check(TreeNode* root,int val){
        if(root!=NULL){
            check(root->left,val);
            if(root->val!=val) ans = 1;
            check(root->right,val);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        check(root,root->val);
        if(ans) return false;
        else return true;
    }
};

int main(){
    
    return 0;
}