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
    TreeNode* root;
    TreeNode* temp;
    void insert(TreeNode* root,int val,TreeNode* parent){
        if(root==NULL){
            TreeNode* newNode = new TreeNode(val);
            if(val>parent->val){
                parent->right = newNode;
            }
            else parent->left = newNode;
            return;
        }
        if(val>root->val) insert(root->right,val,root);
        else insert(root->left,val,root);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        if(size==0) return NULL;
        TreeNode* newNode = new TreeNode(preorder[0]);
        root = newNode;
        temp = root;
        if(size==1) return root;
        for(int i=1;i<size;i++){
            insert(temp,preorder[i],temp);
        }
        return root;
    }
};

int main(){
    
    return 0;
}