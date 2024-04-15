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
    int result=0;
    string s="";
    void myFunction(TreeNode* root){
        if(!root->left && !root->right){
            result+=stoi(s);
            return;
        }
        if(root->left){
            s+=to_string(root->left->val);
            myFunction(root->left);
            s.pop_back();
        }
        if(root->right){
            s+=to_string(root->right->val);
            myFunction(root->right);
            s.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        s+=to_string(root->val);
        myFunction(root);
        return result;
    }
};