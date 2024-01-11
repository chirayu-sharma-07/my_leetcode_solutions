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

        // Approach one
        // Converting Binary tree into undirected graph
        // Applying BFS on that graph

        unordered_map<int,vector<int>> um;
        stack<pair<TreeNode *,int>> st;
        st.push(make_pair(root,-1));
        while(!st.empty()){
            TreeNode *t=st.top().first;
            int hasParent=st.top().second;
            st.pop();
            if(hasParent!=-1) um[t->val].push_back(hasParent);
            if(t->right!=NULL){
                um[t->val].push_back(t->right->val);
                st.push(make_pair(t->right,t->val));
            }
            if(t->left!=NULL){
                um[t->val].push_back(t->left->val);
                st.push(make_pair(t->left,t->val));
            }
        }
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int x=1;
        int result=0;
        while(!q.empty()){
            int count=0;
            while(x!=0){
                int num=q.front();
                q.pop();
                int n=um[num].size();
                for(int e=0;e<n;e++){
                    int f=um[num][e];
                    if(visited.find(f)==visited.end()){
                        visited.insert(f);
                        count++;
                        q.push(f);
                    }
                }
                x--;
            }
            x=count;
            result++;
        }
        return result-1;
    }
};