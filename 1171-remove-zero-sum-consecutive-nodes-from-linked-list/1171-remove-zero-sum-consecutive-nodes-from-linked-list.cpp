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

        // First approach (Brute force with O(N^2) TC)

        /*
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
        */

        // Second approach (using map)

        unordered_map<int,ListNode*> myMap;
        int sum=0;
        ListNode *myNode=new ListNode(0);
        myNode->next=head;
        myMap[0]=myNode;
        while(head){
            sum+=head->val;
            if(myMap.find(sum)!=myMap.end()){
                ListNode *p1,*p2;
                p1=p2=myMap[sum];
                int sub_sum=sum;
                while(p2!=head){
                    p2=p2->next;
                    sub_sum+=p2->val;
                    if(p2!=head){
                        myMap.erase(sub_sum);
                    }
                }
                p1->next=p2->next;
            }else myMap[sum]=head;
            head=head->next;
        }
        return myNode->next;
    }
};