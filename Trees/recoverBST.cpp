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
    TreeNode* first;
    TreeNode* second;
    void Inorder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }
    void find1(TreeNode* root,int val){
        if(root==NULL) return;
        find1(root->left,val);
        if(root->val==val){
            first = root;
            return;
        };
        find1(root->right,val);
    }
    void find2(TreeNode* root,int val){
        if(root==NULL) return;
        find2(root->left,val);
        if(root->val==val){
            second = root;
            return;
        };
        find2(root->right,val);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> res; 
        Inorder(root,res);
        vector<int> sorted(res);
        int val1,val2;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<res.size();i++){
            if(res[i]!=sorted[i]){
                val1 = res[i];
                val2 = sorted[i];
                break;
            }
        }
        find1(root,val1);
        find2(root,val2);
        swap(first->val,second->val);
    }
};

int main(){
    
    return 0;
}