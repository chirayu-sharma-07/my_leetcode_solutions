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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m,vector<int>(n,-1));
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        while(top<=bottom && left<=right){
            for(int e=left;head!=NULL && e<=right;e++){
                result[top][e]=head->val;
                head=head->next;
            }
            if(head==NULL) return result;
            top++;
            for(int e=top;head!=NULL && e<=bottom;e++){
                result[e][right]=head->val;
                head=head->next;
            }
            if(head==NULL) return result;
            right--;
            for(int e=right;head!=NULL && e>=left;e--){
                result[bottom][e]=head->val;
                head=head->next;
            }
            if(head==NULL) return result;
            bottom--;
            for(int e=bottom;head!=NULL && e>=top;e--){
                result[e][left]=head->val;
                head=head->next;
            }
            if(head==NULL) return result;
            left++;
        }
        return result;
    }
};