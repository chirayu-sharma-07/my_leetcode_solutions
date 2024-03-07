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
        if(!head) return NULL;
        unordered_map<ListNode*,bool> myMap;
        while(head){
            if(myMap[head]==true) return head;
            myMap[head]=true;
            head=head->next;
        }
        return NULL;
    }
};