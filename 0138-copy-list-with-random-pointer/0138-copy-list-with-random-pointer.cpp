/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // First approach

        if(head==NULL) return head;
        Node *new_head=NULL;
        Node *s=head;
        Node *prev=NULL;
        unordered_map<Node*,Node*> myMap;
        while(s){
            Node *new_node=new Node(s->val);
            if(prev==NULL){
                new_head=new_node;
                prev=new_node;
            }else{
                prev->next=new_node;
                prev=prev->next;
            }
            myMap[s]=new_node;
            s=s->next;
        }
        s=head;
        Node *t=new_head;
        while(s){
            if(s->random==NULL){
                t->random=NULL;
            }else t->random=myMap[s->random];
            s=s->next;
            t=t->next;
        }
        return new_head;
    }
};