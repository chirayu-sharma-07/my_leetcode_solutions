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
private:
    int Val,Depth;
public:

    // First approach (Return type of myFunction is TreeNode*)

    /*
    int Depth=0;
    int Val=0;
    TreeNode* myFunction(TreeNode* root,int curr_level){
        if(root==NULL) return root;
        if(curr_level==Depth-1){
            TreeNode *left_temp=root->left;
            TreeNode *right_temp=root->right;
            root->left=new TreeNode(Val);
            root->right=new TreeNode(Val);
            root->left->left=left_temp;
            root->right->right=right_temp;
            return root;
        }
        root->left=myFunction(root->left,curr_level+1);
        root->right=myFunction(root->right,curr_level+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *new_node=new TreeNode(val);
            new_node->left=root;
            return new_node;
        }
        Depth=depth;
        Val=val;
        return myFunction(root,1);
    }
    */

    // Second approach (Return type is void)


    void myFunction(TreeNode *root,int level){
        if(!root) return;
        if(level==Depth-1){
            TreeNode *first=root->left;
            TreeNode *second=root->right;
            root->left=new TreeNode(Val);
            root->right=new TreeNode(root->left->val);
            if(root->left) root->left->left=first;
            if(root->right) root->right->right=second;
        }
        myFunction(root->left,level+1);
        myFunction(root->right,level+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *new_root=new TreeNode(val);
            new_root->left=root;
            return new_root;
        }
        Val=val;
        Depth=depth;
        myFunction(root,1);
        return root;
    }
};