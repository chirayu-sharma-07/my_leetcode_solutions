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
        if(!head->next) return head;
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
    void reorderList(ListNode* head) {
        
        // First approach (Using Stack)

        /*
        if(!head->next || !head->next->next) return;
        ListNode *myNode=new ListNode(7);
        myNode->next=head;
        ListNode *slow=myNode;
        ListNode *fast=myNode;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow;
        stack<ListNode *> st;
        while(slow->next){
            st.push(slow->next);
            slow=slow->next;
        }
        fast->next=NULL;
        slow=myNode->next;
        while(slow && !st.empty()){
            fast=slow->next;
            slow->next=st.top();
            st.pop();
            slow->next->next=fast;
            slow=slow->next->next;
        }
        return;
        */

        // Second approach (By reversing right half of the linked list)

        if(!head->next || !head->next->next) return;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=reverse_linked_list(slow->next);
        slow->next=NULL;
        slow=head;
        while(fast){
            ListNode *temp=slow->next;
            slow->next=fast;
            fast=fast->next;
            slow->next->next=temp;
            slow=slow->next->next;
        }
        return;
    }
};