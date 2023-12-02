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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        //Third class approach
        vector<int> vec;
        for(ListNode *list=head;list!=NULL;list=list->next) vec.push_back(list->val);
        sort(vec.begin(),vec.end());
        int e=0;
        for(ListNode *list=head;list!=NULL;list=list->next,e++) list->val=vec[e];
        return head;
    }
};