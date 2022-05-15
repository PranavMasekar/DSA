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
    void Inorder(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
    }
    TreeNode* solution(vector<int> vec,int low,int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solution(vec,low,mid-1);
        root->right = solution(vec,mid+1,high);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        Inorder(root,vec);
        int n = vec.size();
        return solution(vec,0,n-1);
    }
};

int main(){
    
    return 0;
}