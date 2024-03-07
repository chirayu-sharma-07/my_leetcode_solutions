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
        unordered_map<Node*,Node*> myMap;
        Node *prev=new Node(7);
        Node *temp=prev;
        Node *temp_two=head;
        while(head){
            Node *myNode=new Node(head->val);
            prev->next=myNode;
            prev=myNode;
            myMap[head]=myNode;
            head=head->next;
        }
        prev->next=NULL;
        head=temp->next;
        while(temp_two){
            head->random=myMap[temp_two->random];
            temp_two=temp_two->next;
            head=head->next;
        }
        return temp->next;
    }
};