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
    void solve(TreeNode* root,map<int,int> &ans){
        if(root==NULL) return;
        else{
            ans[root->val]++;
            solve(root->left,ans);
            solve(root->right,ans);
            return;
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->val);
            return res;
        }
        map<int,int> ans;
        solve(root,ans);
        int max = 1;
        for(auto it : ans){
            if(it.second>max){
                max = it.second;
            }
        }
        for(auto it : ans){
            if(it.second==max){
                res.push_back(it.first);
            }
        }
        // res.push_back(key);
        return res;
    }
};

int main(){
    
    return 0;
}