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
    int solve(TreeNode *root){
        if(root==NULL) return 0;
        int result=0;
        if(root->val%2!=0){
            result+=solve(root->left);
            result+=solve(root->right);
        }else{
            if(root->left!=NULL){
                if(root->left->left!=NULL) result+=root->left->left->val;
                if(root->left->right!=NULL) result+=root->left->right->val;
                result+=solve(root->left);
            }
            if(root->right!=NULL){
                if(root->right->right!=NULL) result+=root->right->right->val;
                if(root->right->left!=NULL) result+=root->right->left->val;
                result+=solve(root->right);
            }
        }
        return result;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root);
    }
};