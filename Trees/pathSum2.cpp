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
    vector<vector<int>> ans;
    void solution(TreeNode* root,int sum,vector<int>path){
        if(root==NULL) return;
        sum -= root->val;
        path.push_back(root->val);
        solution(root->left,sum,path);
        if(sum==0 && root->left==NULL && root->right==NULL){
            ans.push_back(path);
        }
        solution(root->right,sum,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solution(root,targetSum,path);
        return ans;
    }
};

int main(){
    
    return 0;
}