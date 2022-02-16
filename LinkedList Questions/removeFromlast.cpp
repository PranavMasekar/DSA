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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        int length = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        int pos = length - n;
        if (pos == 0)
            return head->next;
        ptr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        ListNode *temp = ptr->next;
        ptr->next = temp->next;
        return head;
    }
};

int main()
{

    return 0;
}