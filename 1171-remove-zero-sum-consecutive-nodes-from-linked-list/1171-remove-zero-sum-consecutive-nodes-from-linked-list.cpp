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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *myNode=new ListNode(7);
        myNode->next=head;
        ListNode *p1=myNode;
        ListNode *p2=NULL;
        while(p1 && p1->next){
            int sum=0;
            p2=p1->next;
            while(p2){
                sum=sum+p2->val;
                if(!sum){
                    p1->next=p2->next;
                }
                p2=p2->next;
            }
            p1=p1->next;
        }
        return myNode->next;
    }
};