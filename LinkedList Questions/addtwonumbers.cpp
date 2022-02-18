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
    ListNode *reverseList(ListNode *head,int &length)
    {   
        if(head==NULL || head->next==NULL)return head;
        ListNode * previous = NULL;
        ListNode * present = head;
        ListNode * next = present->next;
        while(present!=NULL){
            length++;
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
    ListNode * insertAddHead(ListNode * head, int val){
        if(head==NULL){
            ListNode * newnode;
            newnode->val = val;
            newnode->next=NULL;
            head = newnode;
            return head;
        }
        else{
            ListNode * newnode;
            newnode->val = val;
            newnode->next = head;
            head = newnode;
            return head;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = 0,length2=0;
        l1 = reverseList(l1,length1);
        l2 = reverseList(l2,length2);
        length1--;
        length2--;
        int number1 = 0;
        int number2 = 0;
        ListNode * ptr = l1;
        while(ptr!=NULL){
            number1 += ptr->val * pow(10,length1);
            ptr = ptr->next;
        }
        ptr = l2;
        while(ptr!=NULL){
             number2 += ptr->val * pow(10,length2);
            ptr = ptr->next;
        }
        int final  = number1 + number2;
        ListNode * res = NULL;
        while(final>0){
            int n = final % 10;
            res = insertAddHead(res,n);
            final  = final /10;
        }
        res = reverseList(res,length1);
        return res;
    }
};

int main(){
    
    return 0;
}