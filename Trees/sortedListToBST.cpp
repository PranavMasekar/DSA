#include<bits/stdc++.h>
using namespace std;

// MEMORY LIMIT EXCEDDED

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    TreeNode* solution(vector<int> vec,int low,int high){
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solution(vec,low,mid-1);
        root->right = solution(vec,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while(head!=NULL) vec.push_back(head->val);
        return solution(vec,0,vec.size()-1);
    }
};

int main(){
    
    return 0;
}