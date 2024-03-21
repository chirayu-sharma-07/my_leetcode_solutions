/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p1=NULL;
        ListNode *p2=head->next;
        while(p2){
            head->next=p1;
            p1=head;
            head=p2;
            p2=p2->next;
        }
        head->next=p1;
        return head;
    }
};