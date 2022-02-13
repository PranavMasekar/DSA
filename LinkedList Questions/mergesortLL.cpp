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
//Not working on leetcode 
// Merge Function
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    if (list2 == NULL)
        return list1;
    if (list1 == NULL)
        return list2;
    // Tranversing untill anythinh ll reaches end
    while (list1 != NULL && list2 != NULL)
    {
        // Adding small value in linkedlist
        if (list1->val < list2->val)
        {
            ListNode *newnode = new ListNode(list1->val);
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            tail->next = newnode;
            tail = tail->next;
            list1 = list1->next;
        }
        else if (list2->val < list1->val)
        {
            ListNode *newnode = new ListNode(list2->val);
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            tail->next = newnode;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    // Adding reamaining element from first ll
    while (list1 != NULL)
    {
        ListNode *newnode = new ListNode(list1->val);
        tail->next = newnode;
        tail = tail->next;
        list1 = list1->next;
    }
    // Adding reamaining element from second ll
    while (list2 != NULL)
    {
        ListNode *newnode = new ListNode(list2->val);
        tail->next = newnode;
        tail = tail->next;
        list2 = list2->next;
    }
    return head;
}

// Find middle of the function
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *sortList(ListNode *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode * middle = middleNode(head);
    ListNode * left = sortList(head);
    ListNode * right = sortList(middle);
    return mergeTwoLists(left,right);
}

int main()
{
    return 0;
}