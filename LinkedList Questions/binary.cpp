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
    int getDecimalValue(ListNode* head) {
        int size = 1;
        ListNode * ptr = head;
        while(ptr->next!=NULL){
            size++;
            ptr = ptr->next;
        }
        int power = size -1;
        int ans = 0;
        ptr = head;
        while(ptr!=NULL && power>=0){
            ans += ptr->val * pow(2,power);
            power--;
            ptr = ptr->next;
        }
        return ans;
    }
};

int main(){
    
    return 0;
} 