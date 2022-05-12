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
    bool checkEven(vector<int> temp){
        if(temp.size()==1){
            if(temp[0]%2==0) return false;
            else return true;
        }
        if(temp[0]%2==0) return false;
        for(int i=1;i<temp.size();i++){
            if(temp[i]%2==0) return false;
            else{
                if(temp[i-1]>=temp[i]) return false;
            }
        }
        return true;
    }
    bool checkOdd(vector<int> temp){
        if(temp.size()==1){
            if(temp[0]%2!=0) return false;
            else return true;
        }
        if(temp[0]%2!=0) return false;
        for(int i=1;i<temp.size();i++){
            if(temp[i]%2!=0) return false;
            else{
                if(temp[i]>=temp[i-1]) return false;
            }
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0) return false;
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
            if(level==1){
                for(int i=0;i<temp.size();i++) cout<<temp[i]<<" "<<endl;
            }
            if(level%2!=0){
                if(!checkOdd(temp)) return false;
            }
            else {
                if(!checkEven(temp)) return false;
            }
            level++;
        }
        return true;
    }
};

int main(){
    
    return 0;
}