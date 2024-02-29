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

        // First approach

        /*
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
        */

        // Second approach

        /*
        vector<TreeNode*> vec;
        vec.push_back(root);
        int level=0;
        while(vec.size()!=0){
            int n=vec.size();
            if(level==0){
                if(vec[0]->val%2==0) return false;
                for(int e=1;e<n;e++){
                    if(vec[e-1]->left) vec.push_back(vec[e-1]->left);
                    if(vec[e-1]->right) vec.push_back(vec[e-1]->right);
                    if(vec[e]->val%2==0 || vec[e-1]->val>=vec[e]->val) return false;
                }
                if(vec[n-1]->left) vec.push_back(vec[n-1]->left);
                if(vec[n-1]->right) vec.push_back(vec[n-1]->right);
                level=1;
            }else{
                if(vec[0]->val%2!=0) return false;
                for(int e=1;e<n;e++){
                    if(vec[e-1]->left) vec.push_back(vec[e-1]->left);
                    if(vec[e-1]->right) vec.push_back(vec[e-1]->right);
                    if(vec[e]->val%2!=0 || vec[e-1]->val<=vec[e]->val) return false;
                }
                if(vec[n-1]->left) vec.push_back(vec[n-1]->left);
                if(vec[n-1]->right) vec.push_back(vec[n-1]->right);
                level=0;
            }
            vec.erase(begin(vec),begin(vec)+n);
        }
        return true;
        */

        // Third approach (Smooth code)

        queue<TreeNode*> kyu;
        kyu.push(root);
        int flag=0;
        while(!kyu.empty()){
            int sz=kyu.size();
            int prev_one=INT_MIN;
            int prev_two=INT_MAX;
            while(sz--){
                TreeNode* curr_node=kyu.front(); kyu.pop();
                if(curr_node->left) kyu.push(curr_node->left);
                if(curr_node->right) kyu.push(curr_node->right);
                if(flag==0){
                    if(!(curr_node->val%2)) return false;
                    if(curr_node->val>prev_one) prev_one=curr_node->val;
                    else return false;
                }else{
                    if(curr_node->val%2) return false;
                    if(curr_node->val<prev_two) prev_two=curr_node->val;
                    else return false;
                }
                
            }
            if(flag==0) flag=1;
            else flag=0;
        }
        return true;
    }
};