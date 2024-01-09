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

    vector<int> vec1;
    vector<int> vec2;
    void myFunction(TreeNode *root){
        if(root->left!=NULL) myFunction(root->left);
        if(root->right!=NULL) myFunction(root->right);
        if(root->left==NULL && root->right==NULL) vec1.push_back(root->val);
    }
    void myFunction1(TreeNode *root){
        if(root->left!=NULL) myFunction1(root->left);
        if(root->right!=NULL) myFunction1(root->right);
        if(root->left==NULL && root->right==NULL) vec2.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vec1.clear();
        vec2.clear();
        myFunction(root1);
        myFunction1(root2);
        int e=vec1.size();
        int f=vec2.size();
        int i=0;
        int j=0;
        while(i<e && j<f){
            if(vec1[i]!=vec2[j]) return false;
            i++;j++;
        }
        if(i==e && j<f || j==f && i<e) return false;
        return true;
    }
};