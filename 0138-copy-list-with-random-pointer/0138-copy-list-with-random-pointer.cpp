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

        Node *new_head=NULL;
        Node *prev=NULL;
        Node *e=head;
        unordered_map<Node*,Node*> myMap;
        while(e){
            Node *new_node=new Node(e->val);
            if(new_head==NULL){
                new_head=new_node;
                prev=new_node;
            }else{
                prev->next=new_node;
                prev=new_node;
            }
            myMap[e]=new_node;
            e=e->next;
        }
        e=head;
        prev=new_head;
        while(e){
            prev->random=myMap[e->random];
            e=e->next;
            prev=prev->next;
        }
        return new_head;
    }
};