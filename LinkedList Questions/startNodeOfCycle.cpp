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
    int LengthOfCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        int count = 0;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                // Calculate the length
                // start the pointer from one step next from slow then count the elements
                ListNode *temp = slow;
                do {
                    temp = temp->next;
                    count++;
                } while (temp != slow);
                return count;
            }
        }
        return 0;
    }

    ListNode *detectCycle(ListNode *head)
    {
        int length = 0;
        ListNode *fast = head, *slow = head;
        // Finding the cycle and getting the length of the cycle
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                length = LengthOfCycle(slow);
                break;
            }
        }
        if (length == 0)
        {
            return NULL;
        }
        // Now We got the length of cycle if present
        ListNode *first = head;
        ListNode *second = head;
        // Moving second pointer lenghth of cycle times
        while (length > 0)
        {
            second = second->next;
            length--;
        }
        // Now keep moving first and second pointer untill they point to same position
        while (first != second)
        {
            first = first->next;
            second = second->next;
        }

        return second;
    }
};

int main()
{

    return 0;
}