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
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int currentDepth = 0;
        for(auto it :  root->children){
            currentDepth = max(currentDepth,maxDepth(it));
        }
        return currentDepth + 1;
    }
};

int main(){
    
    return 0;
}