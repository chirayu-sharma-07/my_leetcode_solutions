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
    ListNode* insertionSortList(ListNode* head) {
        //Third class approach
        vector<int> vc;
        for(ListNode* e=head;e!=NULL;e=e->next) vc.push_back(e->val);
        sort(begin(vc),end(vc));
        int e=0;
        int vc_size=vc.size();
        for(ListNode* f=head;e<vc_size;e++){
            f->val=vc[e];
            f=f->next;
        }
        return head;
    }
};