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
    // Swapping actual nodes
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *current = head;
        ListNode *prev = new ListNode;
        ListNode *next = head->next;
        head = next;

        while (current != NULL)
        {
            next = current->next;
            if (next == NULL)
                break;
            ListNode *newNext = next->next;
            next->next = current;
            current->next = newNext;
            if (prev != NULL)
            {
                prev->next = next;
            }
            prev = current;
            current = current->next;
        }
        return head;
    }
    // Just swapping values
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *current = head;
        while (current != NULL)
        {
            if (current->next == NULL)
                break;
            swap(current->val, current->next->val);
            current = current->next->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}