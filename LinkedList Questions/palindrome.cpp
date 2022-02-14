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
    // LL reversal
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *previous = NULL;
        ListNode *present = head;
        ListNode *next = present->next;
        while (present != NULL)
        {
            present->next = previous;
            previous = present;
            present = next;
            if (next != NULL)
            {
                next = next->next;
            }
        }
        head = previous;
        return head;
    }
    // Middle of the LL
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
    // Reverse the second half of the ll then compare first and second half 
    // If both are same then return true else false
    // E.X. 1->2->5->6->9->7
    //      1->2->5->7->9->6
    // Now one pointer is at 1 and second one at 7  start checking if ther are equal 
    // In the end reReverse the second half of the LL
    bool isPalindrome(ListNode *head)
    {
        ListNode * middle = middleNode(head);
        ListNode * secondHead = reverseList(middle);
        // Storing secondHead into another pointer so we can reReverse later
        ListNode * tempSecondHead = secondHead;

        while(head!=NULL && tempSecondHead!=NULL){
            if(head->val!=tempSecondHead->val){
                break;
            }
            head= head->next;
            tempSecondHead = tempSecondHead->next;
        }
        reverseList(secondHead);
        if(head==NULL || tempSecondHead==NULL)return true;
        else return false;
    }
};

int main()
{

    return 0;
}