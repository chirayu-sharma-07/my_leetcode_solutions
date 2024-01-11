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
    
    /*
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
    */

    // Approach two
    // Optimized approach

    int myFunction(TreeNode *root,int minimum,int maximum){
        if(root==NULL){
            return abs(minimum-maximum);
        }
        minimum=(minimum>root->val)?root->val:minimum;
        maximum=(root->val<maximum)?maximum:root->val;
        int e=myFunction(root->left,minimum,maximum);
        int f=myFunction(root->right,minimum,maximum);
        return (e>f)?e:f;
    }
    int maxAncestorDiff(TreeNode* root){
        int minimum=INT_MAX;
        int maximum=INT_MIN;
        return myFunction(root,minimum,maximum);
    }
};