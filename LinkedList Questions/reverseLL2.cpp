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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        // Skip the first left-1 nodes to get desire pointer to node
        ListNode *present = head;
        ListNode *previous = NULL;
        for (int i = 0; present != NULL && i < left - 1; i++)
        {
            previous = present;
            present = present->next;
        }
        // Getting node just before the first node from where we have to reverse the LL
        ListNode *last = previous;
        ListNode *newEnd = present;
        // Iterating number of elements times in ll
        ListNode *next = present->next;
        for (int i = 0; present != NULL && i < right - left + 1; i++)
        {
            present->next = previous;
            previous = present;
            present = next;
            if (next != NULL)
            {
                next = next->next;
            }
        }
        if (last != NULL)
        {
            last->next = previous;
        }
        else
        {
            head = previous;
        }
        newEnd->next = present;
        return head;
    }
};

int main()
{

    return 0;
}