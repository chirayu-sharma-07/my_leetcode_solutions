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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> us;
        stack<pair<TreeNode *,int>>st;
        st.push(make_pair(root,-1));
        while(!st.empty()){
            TreeNode *t=st.top().first;
            int hasParent=st.top().second;
            st.pop();
            if(hasParent!=-1) us[t->val].push_back(hasParent);
            if(t->right!=NULL){
                st.push(make_pair(t->right,t->val));
                us[t->val].push_back(t->right->val);
            }
            if(t->left!=NULL){
                st.push(make_pair(t->left,t->val));
                us[t->val].push_back(t->left->val);
            }
        }
        int result=0;
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int x=1;
        while(!q.empty()){
            int num=0;
            int push_count=0;
            while(x!=0){
                num=q.front();
                q.pop();
                int n=us[num].size();
                for(int e=0;e<n;e++){
                    int y=us[num][e];
                    if(visited.find(y)==visited.end()){
                        visited.insert(y);
                        push_count++;
                        q.push(y);
                }
            }
            x--;
            }
            x=push_count;
            result++;
        }
        return result-1;
    }
};