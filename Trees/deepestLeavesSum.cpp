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

// Incomplete
// TODO:

class Solution {
public:
    int maxDepth = 0;
    void traverse(TreeNode* root,vector<int>& leaves){
        if (root != NULL)
        {
            traverse(root->left, leaves);
            if(root->left==NULL && root->right==NULL) leaves.push_back(root->val);
            traverse(root->right, leaves);
        }
    }
    int depth(TreeNode* root,int val,int x){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){

        if(root->val==val) return x;
        }
        int left =  depth(root->left,val,x +1);
        if(left!=0) return left;
        int right = depth(root->right,val,x +1);
        return right;
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,int> map;
        vector<int> leaves;
        traverse(root,leaves);
        for(int i=0;i<leaves.size();i++){
            map[leaves[i]] = depth(root,leaves[i],1);
        }
        int res = 0;
        for(auto it : map){
            maxDepth = max(maxDepth,it.second);
        }
        for(auto it : map){
            cout<<it.second<<endl;
            if(it.second==maxDepth){
                res += it.first;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}