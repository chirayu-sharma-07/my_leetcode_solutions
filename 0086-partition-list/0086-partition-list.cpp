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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        //here p is denotion pointers
        ListNode *myList1=new ListNode(7);
        myList1->next=head;
        ListNode *p1=myList1;
        while(p1->next!=NULL){
            if(p1->next->val>=x) break;
            p1=p1->next;
        }
        if(p1->next==NULL) return head;
        ListNode *myList2=new ListNode(77);
        myList2->next=NULL;
        ListNode *p2=myList2;
        p2->next=p1->next;
        p1->next=NULL;
        while(p2!=NULL && p2->next!=NULL){
            if(p2->next->val<x){
                p1->next=p2->next;
                p2->next=p2->next->next;
                p1->next->next=NULL;
                p1=p1->next;
            }else p2=p2->next;
        }
        p1->next=myList2->next;
        return myList1->next;
    }
};