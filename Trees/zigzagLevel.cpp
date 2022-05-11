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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* popped = q.front();
                q.pop();
                temp.push_back(popped->val);
                if(popped->left!=NULL) q.push(popped->left);
                if(popped->right!=NULL) q.push(popped->right);
            }
            if(level%2!=0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else ans.push_back(temp);
            level++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}