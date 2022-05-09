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
    int sum = 0;
    void addToSum(TreeNode* root){
        if(root->left!=NULL) sum += root->left->val;
        if(root->right!=NULL) sum += root->right->val;
    }
    void solution(TreeNode* root){
        if(root==NULL) return;
        if(root->val%2 == 0){
            if(root->left!=NULL) addToSum(root->left);
            if(root->right!=NULL) addToSum(root->right);
        }
        solution(root->left);
        solution(root->right);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        solution(root);
        return sum;
    }
};

int main(){
    
    return 0;
}