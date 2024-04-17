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
    vector<string> vec;
    string s="";
    string reverseString(string s){
        int e=0;
        int f=s.size()-1;
        while(e<f){
            char c=s[e];
            s[e]=s[f];
            s[f]=c;
            e++;
            f--;
        }
        return s;
    }
    void myFunction(TreeNode *root){
        if(!root->left && !root->right){
            vec.push_back(reverseString(s));
        }
        if(root->left){
            s.push_back(root->left->val+'a');
            myFunction(root->left);
            s.pop_back();
        }
        if(root->right){
            s.push_back(root->right->val+'a');
            myFunction(root->right);
            s.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        s.push_back(root->val+'a');
        myFunction(root);
        sort(begin(vec),end(vec));
        return vec[0];
    }
};