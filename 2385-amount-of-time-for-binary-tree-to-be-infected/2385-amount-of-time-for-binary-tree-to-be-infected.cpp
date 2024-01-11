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
    // Converted Binary tree into undirected graph
    // Applied BFS on that graph

    /*

    int amountOfTime(TreeNode* root, int start) {    
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
    
    */
    
    // Approach two
    // One pass solution
    // Recursive approach

    int result=INT_MIN;
    int st=0;
    int myFunction(TreeNode *root){
        if(root==NULL) return 0;
        int left_sub_tree=myFunction(root->left);
        int right_sub_tree=myFunction(root->right);
        if(root->val==st){
            result=(left_sub_tree>right_sub_tree)?left_sub_tree:right_sub_tree;
            return -1;
        }else if(left_sub_tree>=0 && right_sub_tree>=0){
            return ((left_sub_tree<right_sub_tree)?right_sub_tree:left_sub_tree)+1;
        }else{
            int e=abs(left_sub_tree)+abs(right_sub_tree);
            result=(result>e)?result:e;
            return ((left_sub_tree>right_sub_tree)?right_sub_tree:left_sub_tree)-1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        st=start;
        myFunction(root);
        return result;
    }
};