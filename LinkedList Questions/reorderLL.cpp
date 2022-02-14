#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
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
    // Rorder LL
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode * middle = middleNode(head);
        ListNode * secondhead = reverseList(middle);
        ListNode * firsthead = head;
        
        while(firsthead!=NULL && secondhead!=NULL){
            // E.X. our original LL 1->2->3->5->6
            // Before we link 1 and 6 we need to get the pointer to node 2 so we can connect later
            ListNode * temp = firsthead->next;
            firsthead->next = secondhead;
            firsthead = temp;
            // Connected 1->6 and move our firsthead to 2
            // Now similar we have to connect secondhead i.e. 6 to firsthead i.e. 2
            // We also need to store the secondhead next 
            temp = secondhead->next;
            secondhead->next = firsthead;
            secondhead = temp;
            // Now LL is 1->6->2
        }

        if(firsthead!=NULL){
            firsthead->next =NULL;
        }
    }
};

int main(){
    
    return 0;
}