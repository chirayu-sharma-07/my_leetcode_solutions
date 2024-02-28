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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> vec;
        vec.push_back(root);
        int result=root->val;
        while(true){
            int n=vec.size();
            for(int e=0;e<n;e++){
                if(vec[e]->left) vec.push_back(vec[e]->left);
                if(vec[e]->right) vec.push_back(vec[e]->right);
            }
            vec.erase(begin(vec),begin(vec)+n);
            if(vec.size()==0) return result;
            result=vec[0]->val;
        }
        return result;
    }
};