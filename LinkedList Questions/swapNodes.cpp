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
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        int length = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 1; i < k; i++)
        {
            first = first->next;
        }
        for (int i = 1; i <= length - k; i++)
        {
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};

int main()
{

    return 0;
}