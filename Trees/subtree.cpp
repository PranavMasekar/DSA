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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL && q !=NULL) ||(q==NULL && p!= NULL) ) return false;
        if(p==NULL && q == NULL) return true;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    TreeNode * findNode(TreeNode* p,int val){
        if(p==NULL || p->val==val) return p;
        else if(p->val<val){
            return findNode(p->right,val);
        }
        else {
            return findNode(p->left,val);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* node = findNode(root,subRoot->val);
        return isSameTree(node,subRoot);    
    }
};


int main(){
    
    return 0;
}