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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 1;
        if(k<=0) return head;
        if(head==NULL || head->next==NULL) return head;
        ListNode * pre = head;
        while (pre->next!=NULL)
        {
            pre = pre->next;
            size++;
        }
        pre->next = head;
        int rotations = k % size;
        int skip = size - rotations;
        ListNode * newlast = head;
        for(int i=0;i<skip-1;i++){
            newlast = newlast->next;
        }
        head = newlast->next;
        newlast->next = NULL;
        return head;
    }
};

int main(){
    
    return 0;
}