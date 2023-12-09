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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        TreeNode *t1=root;
        while(t1!=NULL){
            if(t1->left==NULL){
                result.push_back(t1->val);
                t1=t1->right;
            }else{
                TreeNode *t2=t1->left;
                while(t2->right!=NULL){
                    t2=t2->right;
                }
                t2->right=t1;
                TreeNode *t3=t1;
                t1=t1->left;
                t3->left=NULL;
            }
        }
        return result;
    }
};