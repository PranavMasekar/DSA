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
    int binaryToDecimal(string n) {
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
    void solution(TreeNode* root,string s,vector<string> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s += to_string(root->val);
            ans.push_back(s);
            return ;
        }
         s += to_string(root->val)+"->";
        solution(root->left,s,ans);
        solution(root->right,s,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;
        int res = 0;
        solution(root,"",ans);
        for(int i=0;i<ans.size();i++){
            int num = binaryToDecimal(ans[i]);
            res += num;
        }
        return res;
    }
};

int main(){
    
    return 0;
}