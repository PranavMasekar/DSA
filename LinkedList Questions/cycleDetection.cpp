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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }

    int LengthOfCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        int count = 0;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                // Calculate the length
                // start the pointer from one step next from slow then count the elements 
                ListNode  * ptr = slow->next;
                while(ptr!=slow){
                    count++;
                    ptr = ptr->next;
                }
                return count;
            }
                
        }
        return 0;
    }
};

int main()
{

    return 0;
}