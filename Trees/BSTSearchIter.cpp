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

class BSTIterator {
    vector<int> ans;
    int i = 0;
    void Inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            Inorder(root->left);
            ans.push_back(root->val);
            Inorder(root->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        Inorder(root);
    }
    
    int next() {
        int res = ans[i];
        i++;
        return res;
    }
    
    bool hasNext() {
        if(i==ans.size()) return false;
        else return true;
    }
};

int main(){
    
    return 0;
}