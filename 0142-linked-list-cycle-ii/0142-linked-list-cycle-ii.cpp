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
    ListNode *detectCycle(ListNode *head) {

        // First approach

        /*
        if(!head) return NULL;
        unordered_map<ListNode*,bool> myMap;
        while(head){
            if(myMap[head]==true) return head;
            myMap[head]=true;
            head=head->next;
        }
        return NULL;
        */

        // Second approach

        if(!head) return NULL;
        ListNode *slow=head;
        ListNode *fast=slow;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};