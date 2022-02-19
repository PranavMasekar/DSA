#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    int nextGreater(ListNode * node){
        ListNode * temp = node;
        int current = node->val;
        while(temp!=NULL){
            if(temp->val>current){
                return temp->val;
            }
            temp = temp->next;
        }
        return 0;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode * ptr = head;
        while(ptr!=NULL){
            ans.push_back(nextGreater(ptr));
            ptr = ptr->next;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}