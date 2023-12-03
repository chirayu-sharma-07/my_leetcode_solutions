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
    ListNode* MID(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=slow;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* myFunction(ListNode* left,ListNode* right){
        if(left==NULL || right==NULL) return (left==NULL)?right:left;
        ListNode *newNode=new ListNode(7);
        ListNode *curr=newNode;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        curr->next=(left==NULL)?right:left;
        return newNode->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* midNode=MID(head);
        ListNode* newNode=midNode->next;
        midNode->next=NULL;
        ListNode *left_sub_list=sortList(head);
        ListNode *right_sub_list=sortList(newNode);
        return myFunction(left_sub_list,right_sub_list);
    }
};