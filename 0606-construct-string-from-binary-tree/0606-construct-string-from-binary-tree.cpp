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
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        string str=to_string(root->val);
        if(root->left==NULL && root->right==NULL) return str;
        string left_sub_tree=tree2str(root->left);
        string right_sub_tree=tree2str(root->right);
        if(root->left==NULL){
            return str+"("+")"+"("+right_sub_tree+")";
            return str;
        }
        if(root->right==NULL){
            return str+"("+left_sub_tree+")";
        }
        return str+"("+left_sub_tree+")"+"("+right_sub_tree+")";
    }
};