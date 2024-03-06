/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;
        if(head->next==head) return true;
        if(!head->next->next) return false;
        if(head->next->next==head || head->next->next==head->next) return true;
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        while(fast->next && fast->next->next){
            if(slow==fast) return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};