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
    void reorderList(ListNode* head) {
        
        // First approach (Using Stack)

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
    }
};