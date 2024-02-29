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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0) return false;
        vector<vector<TreeNode*>> vec;
        vector<TreeNode*> sub_vec;
        sub_vec.push_back(root);
        vec.push_back(sub_vec);
        while(true){
            vector<TreeNode*> temp=sub_vec;
            sub_vec.clear();
            for(auto &e:temp){
                if(e->left) sub_vec.push_back(e->left);
                if(e->right) sub_vec.push_back(e->right);
            }
            if(sub_vec.size()==0) break;
            vec.push_back(sub_vec);
        }
        int n=vec.size();
        for(int e=0;e<n;e++){
            vector<int> values_only;
            for(auto &f:vec[e]) values_only.push_back(f->val);
            int m=values_only.size();
            if(e%2==0){
                for(int f=0;f<m-1;f++){
                    if(values_only[f]%2==0 || values_only[f]>=values_only[f+1]) return false;
                }
                if(values_only[m-1]%2==0) return false; 
            }else{
                for(int f=0;f<m-1;f++){
                    if(values_only[f]%2!=0 || values_only[f]<=values_only[f+1]) return false;
                }
                if(values_only[m-1]%2!=0) return false; 
            }
        }
        return true;
    }
};