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

    // First approach

    /*
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
        */

        // Second approach

    /*
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode *myNode=new ListNode(7);
        myNode->next=head;
        ListNode *slow=myNode;
        ListNode *fast=slow;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        head=slow;
        stack<ListNode*> st;
        while(slow->next){
            st.push(slow->next);
            slow=slow->next;
        }
        slow=myNode->next;
        while(!st.empty() && st.top()->val==slow->val){
            st.pop();
            slow=slow->next;
        }
        if(st.empty()){
            if(slow==head || slow==head->next) return true;
        }
        return false;
    }
    */

    // Third approach

    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head=head->next;
        }
        int e=0;
        int f=vec.size()-1;
        while(e<=f){
            if(vec[e]!=vec[f]) return false;
            e++;
            f--;
        }
        return true;
    }
};