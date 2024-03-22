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
    ListNode* reverse_linked_list(ListNode *head){
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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* myNode=new ListNode(7);
        myNode->next=head;
        ListNode* slow=myNode;
        ListNode* fast=myNode;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse_linked_list(slow->next);
        head=slow;
        fast=slow->next;
        slow=myNode->next;
        while(slow && fast && slow->val==fast->val){
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==NULL){
            if(slow==head || slow==head->next) return true;
        }
        return false;
    }
};