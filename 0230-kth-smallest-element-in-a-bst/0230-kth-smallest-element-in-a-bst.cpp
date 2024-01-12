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
    
    // First approach

    /*
    struct Comparator
    {
        bool operator()(const int&a,const int&b)
        {
            return a>b;
        }
    };
    priority_queue<int,vector<int>,Comparator> pq;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        pq.push(root->val);
        myFunction(root->left);
        myFunction(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        myFunction(root);
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
    */


    // Approach two

    /*
    vector<int> vec;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        vec.push_back(root->val);
        myFunction(root->left);
        myFunction(root->right);
    }
    int kthSmallest(TreeNode* root, int k){
        myFunction(root);
        sort(begin(vec),end(vec));
        return vec[k-1];
    }
    */

    // Approach three
    // Inorder traversal

    /*
    vector<int> vec;

    void myFunction(TreeNode *root){
        if(root==NULL) return;
        myFunction(root->left);
        vec.push_back(root->val);
        myFunction(root->right);
    }
    int kthSmallest(TreeNode* root,int k){
        myFunction(root);
        return vec[k-1];    
    }
    */


    // Approach four
    // Inorder traversal without extra memory
    // Most optimized approach

    int K=0;
    int result=0;
    void myFunction(TreeNode *root){
        if(root==NULL) return;
        myFunction(root->left);
        K--;
        if(K==0) result=root->val;
        myFunction(root->right);
    }
    int kthSmallest(TreeNode* root,int k){
        K=k;
        myFunction(root);
        return result;
    }
};