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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        int length = size(head);
        ListNode *pre = head;
        int middle = length / 2;
        for (int i = 0; i < middle - 1; i++)
        {
            pre = pre->next;
        }
        ListNode *next = pre->next->next;
        pre->next = next;
        return head;
    }
};

int main()
{

    return 0;
}