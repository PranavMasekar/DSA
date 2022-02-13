#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Recursion Reverse LL
    ListNode *reverseList(ListNode *head)
    {   
        ListNode * tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        if(head==tail)return NULL;
        reverseList(head->next);
        tail->next = head;
        tail = head;
        tail->next = NULL;

    }
    // WIth Iteration
    ListNode *reverseList(ListNode *head)
    {   
        if(head==NULL || head->next==NULL)return head;
        ListNode * previous = NULL;
        ListNode * present = head;
        ListNode * next = present->next;
        while(present!=NULL){
            present->next = previous;
            previous = present;
            present = next;
            if(next!=NULL){
                next = next->next;
            }
        }
        head = previous;
        return head;
    }
};
int main()
{

    return 0;
}