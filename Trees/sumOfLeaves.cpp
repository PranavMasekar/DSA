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
    int solution(TreeNode* root,int ans,bool isLeft){
        if(root==NULL) return ans;
        else if(root->left==NULL && root->right==NULL && isLeft){
            ans+=root->val;
            return ans;
        }
        else{
            return solution(root->left,ans,true) + solution(root->right,ans,false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solution(root,0,false);
    }
};


int main(){
    
    return 0;
}