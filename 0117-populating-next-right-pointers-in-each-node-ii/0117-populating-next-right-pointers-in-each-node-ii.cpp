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
        if(!root) return root;
        vector<Node*> vec;
        vec.push_back(root);
        int sz=1;
        while(vec.size()!=0){
            int n=0;
            for(int e=0;e<sz;e++){
                if(vec[e]->left){
                    vec.push_back(vec[e]->left);
                    n++;
                }
                if(vec[e]->right){
                    vec.push_back(vec[e]->right);
                    n++;
                }
            }
            int e=0;
            for(;e<sz-1;e++){
                vec[e]->next=vec[e+1];
            }
            vec[e]->next=NULL;
            vec.erase(begin(vec),begin(vec)+sz);
            sz=n;
        }
        return root;
    }
};