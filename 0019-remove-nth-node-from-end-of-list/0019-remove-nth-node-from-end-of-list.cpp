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
    /*
    ListNode* reverseLinkedList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* nxt=head->next;
        while(nxt){
            head->next=prev;
            prev=head;
            head=nxt;
            nxt=nxt->next;
        }
        head->next=prev;
        return head;
    }
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Brute force approach

        /*
        if(head->next==NULL) return NULL;
        ListNode *new_node=new ListNode(7);
        new_node->next=reverseLinkedList(head);
        head=new_node;
        n--;
        while(n--) head=head->next;
        head->next=head->next->next;
        new_node->next=reverseLinkedList(new_node->next);
        return new_node->next;
        */

        // Second approach

        /*
        if(head->next==NULL) return NULL;
        int node_count=2;
        ListNode *temp=head->next->next;
        while(temp){
            node_count++;
            temp=temp->next;
        }
        node_count-=n;
        ListNode *new_node=new ListNode(7);
        new_node->next=head;
        head=new_node;
        while(node_count--){
            head=head->next;
        }
        head->next=head->next->next;
        return new_node->next;
        */

        // Third approach

        ListNode *first_pointer=head;
        ListNode *second_pointer=first_pointer;
        for(int e=0;e<n;e++) first_pointer=first_pointer->next;
        if(!first_pointer) return head->next;
        while(first_pointer->next){
            first_pointer=first_pointer->next;
            second_pointer=second_pointer->next;
        }
        second_pointer->next=second_pointer->next->next;
        return head;
    }
};