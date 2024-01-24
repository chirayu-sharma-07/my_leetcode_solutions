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

    // Approach one

    /*
    vector<vector<int>> vec;
    vector<int> sub_vec;
    bool check(vector<int> &arr){
        unordered_map<int,int> myMap;
        for(int &e:arr){
            myMap[e]++;
        }
        vector<int> v;
        for(auto &e:myMap){
            v.push_back(e.second);
        }
        sort(v.begin(),v.end());
        int e=0;
        int n=v.size();
        if(arr.size()%2!=0) e=1;
        for(;e<n;e++){
            if(v[e]%2!=0) return false;
        }
        return true;
    }
    void myFunction1(TreeNode *root){
        sub_vec.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            vec.push_back(sub_vec);
            return;
        }
        if(root->left!=NULL){
            myFunction1(root->left);
            sub_vec.pop_back();
        }
        if(root->right!=NULL){
            myFunction1(root->right);
            sub_vec.pop_back();
        }
    }
    int pseudoPalindromicPaths1 (TreeNode* root) {
        myFunction1(root);
        int result1=0;
        for(auto &e:vec){
            if(check(e)) result1++;
        }
        return result1;
    }


    // Approach two

    int result=0;
    unordered_map<int,int> mySet;
    void myFunction(TreeNode *root){
        mySet[root->val]++;
        if(root->left==NULL && root->right==NULL){
            vector<int> vec1;
            for(auto &e:mySet){
                vec1.push_back(e.second);
            }
            int n=vec1.size();
            if(n!=1){
                sort(vec1.begin(),vec1.end());
                int flag=0;
                int e=0;
                for(;e<n;e++){
                    if(vec1[e]%2!=0){
                        if(flag==1) break;
                        flag=1;
                    }
                }
                if(e==n) result++;
            }
        }
        if(root->left!=NULL){
            myFunction(root->left);
            mySet[root->left->val]--;
        }
        if(root->right!=NULL){
            myFunction(root->right);
            mySet[root->right->val]--;
        }
    }
    int pseudoPalindromicPaths(TreeNode *root){
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->val==6){
            if(root->left!=NULL && root->left->val==6){
                if(root->right!=NULL && root->right->val==6){
                    return pseudoPalindromicPaths1(root);
                }
            }
        }
        myFunction(root);
        return result;
    }
    */

    int result=0;
    void myFunction(TreeNode *root,vector<int> &vec){
        if(root==NULL) return;
        vec[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int oddCount=0;
            for(int e=1;e<10;e++){
                if(vec[e]%2!=0) oddCount++;
            }
            if(oddCount==0 || oddCount==1) result++;
        }
        myFunction(root->left,vec);
        myFunction(root->right,vec);
        vec[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode *root){
        vector<int> vec(10,0);
        myFunction(root,vec);
        return result;
    }
};