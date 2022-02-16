#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Submitted but not optimized solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
        ListNode *p = headA;
        ListNode *q = headB;
        while (p != NULL)
        {
            while (q != NULL)
            {
                if (p == q)
                    return p;
                else
                    q = q->next;
            }
            q = headB;
            p = p->next;
        }
        return NULL;
    }
    // Optimized Solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int length1 = 0;
        int length2 = 0;
        ListNode *temp = headA;
        // Calculating the length of list 1
        while (temp != NULL)
        {
            length1++;
            temp = temp->next;
        }
        temp = headB;

        // Calculating the length of list 2
        while (temp != NULL)
        {
            length2++;
            temp = temp->next;
        }

        // Now getting the differnece between two list 
        int diff = abs(length1 - length2);
        // so if length1 is greater than length 2 then increase the first pointer by difference size
        // So by doing this we will have two pointers first will be ll which is greater than other and second will be on start of list
        ListNode * first = headA;
        ListNode * second = headB;
        if(length1>length2){
            while(diff>0){
                first = first->next;
                diff--;
            }
        }
        else{
            while(diff>0){
                second = second->next;
                diff--;
            }
        }
        // Now we have our both starting pointer 
        while(first!=NULL && second!=NULL){
            if(first==second) return first;
            first = first->next;
             second = second->next;
        }
        return NULL;
    }
};

int main()
{

    return 0;
}