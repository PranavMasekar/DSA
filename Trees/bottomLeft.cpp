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
    unordered_map<int,vector<int>> map;
    void levelOrder(TreeNode* root) {
        if(root==NULL) return;
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
            map[level] = temp;
            level++;
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        levelOrder(root);
        int maxKey = 0;
        for(auto it : map){
            maxKey = max(maxKey,it.first);
        }
        return map[maxKey][0];
    }
};

int main(){
    
    return 0;
}