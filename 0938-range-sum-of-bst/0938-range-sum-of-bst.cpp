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

    // Approach one

    /*
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int result=0;
        if(root->val>=low && root->val<=high) result+=root->val;
        if(root->left!=NULL){
            result+=rangeSumBST(root->left,low,high);
        }
        if(root->right!=NULL){
            result+=rangeSumBST(root->right,low,high);
        }
        return result;
    }
    */
    
    // Approach two

    /*
    int l=0;
    int h=0;
    int result=0;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        if(root->val>=l && root->val<=h) result+=root->val;
        myFunction(root->left);
        myFunction(root->right);
    }
    int rangeSumBST(TreeNode* root,int low,int high){
        l=low;
        h=high;
        myFunction(root);
        return result;
    }
    */

    // Approach three
    // Best approach

    int l=0;
    int h=0;
    int result=0;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        if(root->left!=NULL && root->val<=l) root->left=NULL;
        if(root->right!=NULL && root->val>=h) root->right=NULL;
        if(root->val>=l && root->val<=h) result+=root->val;
        myFunction(root->left);
        myFunction(root->right);

    }
    int rangeSumBST(TreeNode* root,int low,int high){
        l=low;
        h=high;
        myFunction(root);
        return result;
    }
};