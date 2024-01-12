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
};