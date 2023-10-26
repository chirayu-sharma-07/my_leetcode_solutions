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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==1){
            if(head->next==NULL) return NULL;
            ListNode *l=head;
            for(;l->next->next!=NULL;l=l->next);
            l->next=NULL;
            return head;
        }
        int nodeCount=1;
        for(ListNode *l=head;l->next!=NULL;l=l->next,nodeCount++);
        if(n==nodeCount) return head->next;
        int indexOfNodeToDelete=nodeCount-n;
        ListNode *l=head;
        for(int e=1;e<indexOfNodeToDelete;e++,l=l->next);
        l->next=l->next->next;
        return head;
    }
};