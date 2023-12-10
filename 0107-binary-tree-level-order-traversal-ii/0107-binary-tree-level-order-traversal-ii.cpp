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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        while(!(q.empty())){
            vector<int> sub_result;
            int e=count;
            count=0;
            while(e!=0){
                TreeNode *t=q.front();
                q.pop();
                e--;
                sub_result.push_back(t->val);
                if(t->left!=NULL){
                    count++;
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    count++;
                    q.push(t->right);
                }
            }
            result.push_back(sub_result);
        }
        int vec_size=result.size();
        for(int e=0,f=vec_size-1;e<f;e++,f--){
            vector<int> g=result[e];
            result[e]=result[f];
            result[f]=g;
        }
        return result;
    }
};