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
        if(head==NULL) return false;
        if(head->next==head) return true;
        if(head->next==NULL) return false;
        if(head->next->next==NULL) return false;
        if(head->next->next==head) return true;
        ListNode *p1,*p2;
        p1=p2=head;
        while(p2!=NULL && p2->next!=NULL && p2->next->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
            if(p1==p2) return true;
        }
        return false;
    }
};