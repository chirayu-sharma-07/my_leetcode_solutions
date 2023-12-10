/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        while(!(q.empty())){
            int i=count;
            count=0;
            vector<int> sub_result;
            while(i!=0){
            TreeNode *e=q.front();
            q.pop();
            i--;
            sub_result.push_back(e->val);
            if(e->left!=NULL){
                count++;
                q.push(e->left);
            }
            if(e->right!=NULL){
                count++;
                q.push(e->right);
            }
            }
            result.push_back(sub_result);
        }
        return result;
    }
};