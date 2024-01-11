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

    // Brute force approach
    // Very bad code
    
    int result=0;
    void myFunction(TreeNode *root,TreeNode *child){
        result=max(result,abs(root->val-child->val));
        if(child->left!=NULL) myFunction(root,child->left);
        if(child->right!=NULL) myFunction(root,child->right);
    }
    void recursiveFunction(TreeNode *root){
        if(root->left!=NULL){
            myFunction(root,root->left);
            recursiveFunction(root->left);
        }
        if(root->right!=NULL){
            myFunction(root,root->right);
            recursiveFunction(root->right);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        recursiveFunction(root);
        return result;
    }
};