/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        vector<Node*> vec;
        vec.push_back(root);
        while(vec.size()!=0){
            int n=vec.size();
            int e=0;
            while(e<n-1){
                vec[e]->next=vec[e+1];
                e++;
            }
            vec[e]->next=NULL;
            for(e=0;e<n;e++){
                if(vec[e]->left!=NULL){
                    vec.push_back(vec[e]->left);
                }
                if(vec[e]->right!=NULL){
                    vec.push_back(vec[e]->right);
                }
            }
            vec.erase(begin(vec),begin(vec)+n);
        }
        return root;
    }
};