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
    int maxSum = INT_MIN , maxLevel = 1;
    void levelOrder(TreeNode* root) {
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            int currentSum = 0;
            for(int i=0;i<size;i++){
                TreeNode* popped = q.front();
                q.pop();
                currentSum += popped->val;
                if(popped->left!=NULL) q.push(popped->left);
                if(popped->right!=NULL) q.push(popped->right);
            }
            if(currentSum>maxSum){
                maxSum = currentSum;
                maxLevel = level;
            }
            level++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        levelOrder(root);
        return maxLevel;
    }
};

int main(){
    
    return 0;
}