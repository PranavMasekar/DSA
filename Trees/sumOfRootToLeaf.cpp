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
    void solution(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s += to_string(root->val);
            ans.push_back(s);
            return ;
        }
         s += to_string(root->val);
        solution(root->left,s,ans);
        solution(root->right,s,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;
        int res = 0;
        solution(root,"",ans);
        for(int i=0;i<ans.size();i++){
            int num = stoi(ans[i],0,2);
            res += num;
        }
        return res;
    }
};


int main(){
    
    return 0;
}