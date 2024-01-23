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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p1=head;
        while(p1->next!=NULL){
            int num1=p1->val;
            int num2=p1->next->val;
            int divisor=(num1<num2)?num1:num2;
            while(true){
                if(num1%divisor==0 && num2%divisor==0) break;
                divisor--;
            }
            ListNode *node=new ListNode(divisor);
            node->next=p1->next;
            p1->next=node;
            p1=node->next;
        }
        return head;
    }
};