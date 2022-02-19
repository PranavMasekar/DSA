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
int size(ListNode *head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode * temp = head;
        int length = 0;
        ListNode * tail = new ListNode;
        while(temp->next!=NULL){
            length++;
            temp = temp->next;
        }
        length++;
        tail = temp;
        temp = head;
        for(int i=0;i<length;i++){

        }
    }
};

int main(){
    
    return 0;
}