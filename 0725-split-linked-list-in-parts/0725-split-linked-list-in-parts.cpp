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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        if(head==NULL){
            while(k--) result.push_back(NULL);
            return result;
        }
        int count=1;
        ListNode *p1=head; //p for pointer
        while(p1->next!=NULL){
            count++;
            p1=p1->next;
        }
        if(k>=count){
            if(k>count){
                ListNode *p2=head;
                while(p2!=NULL){
                    ListNode *p3;
                    p3=p2;
                    p2=p2->next;
                    p3->next=NULL;
                    result.push_back(p3);
                    k--;
                }
                while(k--){
                result.push_back(NULL);
                }
            }else{
                ListNode *p2=head;
                while(p2!=NULL){
                    ListNode *p3;
                    p3=p2;
                    p2=p2->next;
                    p3->next=NULL;
                    result.push_back(p3);    
                }
            }
            return result;
        }else{
            int remainder=count%k;
            int pick=count/k;
            while(remainder--){
                ListNode *p2=head;
                int e=0;
                while(e<pick){
                    p2=p2->next;
                    e++;
                }
                ListNode *p3=p2->next;
                p2->next=NULL;
                result.push_back(head);
                head=p3;
                k--;
            }
            while(k--){
                ListNode *p2=head;
                int e=0;
                while(e<pick-1){
                    p2=p2->next;
                    e++;
                }
                ListNode *p3=p2->next;
                p2->next=NULL;
                result.push_back(head);
                head=p3;
            }
        }
        return result;
    }
};