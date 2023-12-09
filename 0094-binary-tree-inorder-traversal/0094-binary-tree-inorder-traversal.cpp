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
    vector<int> result;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        myFunction(root->left);
        result.push_back(root->val);
        myFunction(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        result.clear();
        myFunction(root);
        return result;
    }
};