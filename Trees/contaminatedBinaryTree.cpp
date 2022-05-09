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

class FindElements {
    TreeNode* myRoot;
    TreeNode* temp;
    void solution(TreeNode* root){
        if(root->left!=NULL){
            root->left->val = (2 * root->val) + 1;
            solution(root->left);
        }
        if(root->right!=NULL){
           root->right->val = (2 * root->val) + 2;
           solution(root->right); 
        }
    }
    bool isPresent(TreeNode* root,int val){
        if(root==NULL) return false;
        if(root->val==val) return true;
        return isPresent(root->left,val) || isPresent(root->right,val);
    }
public:
    FindElements(TreeNode* root) {
        if(root==NULL) return;
        myRoot = root;
        temp = myRoot;
        root->val = 0;
        solution(root);
        temp = myRoot;
    }
    
    bool find(int target) {
        bool ans =  isPresent(temp,target);
        temp = myRoot;
        return ans;
    }
};
int main(){
    
    return 0;
}