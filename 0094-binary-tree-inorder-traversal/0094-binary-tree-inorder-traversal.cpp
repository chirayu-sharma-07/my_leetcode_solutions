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
    vector<int> inorderTraversal(TreeNode* root) {

    //Recursive approach

    /*vector<int> result;
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
    }*/
 


    // Traversing approach

    /*vector<int> result;
    if(root==NULL) return result;
    TreeNode *e,*f;
    stack<TreeNode*> stk;
    for(e=root;e!=NULL;e=e->left) stk.push(e);
    while(!(stk.empty())){
        f=stk.top();
        stk.pop();
        result.push_back(f->val);
        if(f->right!=NULL){
            for(e=f->right;e!=NULL;e=e->left) stk.push(e);
        }
    }
    return result;
    */


    //Morris Traversal

    vector<int> result;
    if(root==NULL) return result;
    while(root!=NULL){
        if(root->left==NULL){
            result.push_back(root->val);
            root=root->right;
        }else{
            TreeNode *e=root->left;
            while(e->right!=NULL) e=e->right;
            e->right=root;
            TreeNode *f=root;
            root=root->left;
            f->left=NULL;
        }
    }
    return result;
    }
};