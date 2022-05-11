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

// INCOMPLETE

class Solution {
    int count = 0;
    void solution(TreeNode* root, int targetSum){
        if(root==NULL) return;
        if(targetSum==0) {
            count++;
            return;
        }
        solution(root->left,targetSum);
        solution(root->right,targetSum);
        if(root->val<1) targetSum += root->val;
        else targetSum -= root->val;
        solution(root->left,targetSum);
        solution(root->right,targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        solution(root,targetSum);
        return count;
    }
};
int main(){
    
    return 0;
}