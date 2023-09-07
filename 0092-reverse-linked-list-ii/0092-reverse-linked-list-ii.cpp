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
private:
    ListNode* reverseLinkedList(ListNode *head){
        ListNode *p1=NULL;
        ListNode *p2=head;
        ListNode *p3=head->next;
        while(p3!=NULL){
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p3->next;
        }
        p2->next=p1;
        return p2;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL) return head;
        if(left==right) return head;
        ListNode *myNode=new ListNode(7);
        myNode->next=head;
        int e=0;
        ListNode *p1=myNode;
        while(e<left-1){
            p1=p1->next;
            e++;
        }
        ListNode *p2=p1->next;
        
        while(e<right-1){
            p2=p2->next;
            e++;
        }
        ListNode *p3=p2->next;
        p2->next=NULL;
        p1->next=reverseLinkedList(p1->next);
        if(p3==NULL) return myNode->next;
        p2=p1->next;
        while(p2->next!=NULL) p2=p2->next;
        p2->next=p3;
        return myNode->next;
    }
};