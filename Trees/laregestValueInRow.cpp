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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int maxValue = INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* poppedNode = q.front();
                q.pop();
                maxValue = max(maxValue,poppedNode->val);
                if(poppedNode->left!=NULL) q.push(poppedNode->left);
                if(poppedNode->right!=NULL) q.push(poppedNode->right);
            }
            ans.push_back(maxValue);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}