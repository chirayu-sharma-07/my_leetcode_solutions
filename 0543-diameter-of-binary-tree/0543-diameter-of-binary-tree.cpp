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
    int result=INT_MIN;
    int myFunction(TreeNode *root){
        if(root==NULL) return 0;
        int left=myFunction(root->left);
        int right=myFunction(root->right);
        if((left+right)>result) result=left+right;
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        myFunction(root);
        return result;
    }
};