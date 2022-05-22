#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
    void solution(Node*root,vector<int> &ans){
        if(root!=NULL){
            ans.push_back(root->val);
            for(auto it : root->children){
                solution(it,ans);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        solution(root,ans);
        return ans;
    }
};

int main(){
    
    return 0;
}