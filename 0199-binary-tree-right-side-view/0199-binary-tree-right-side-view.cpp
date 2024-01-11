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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        vector<int> result;
        while(!q.empty()){
            int n=count;
            count=0;
            TreeNode* node=NULL;
            while(n--){
                node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    count++;
                }
                if(node->right){
                    q.push(node->right);
                    count++;
                }
            }
            result.push_back(node->val);
        }
        return result;
    }
};