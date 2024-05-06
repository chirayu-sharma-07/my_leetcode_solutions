/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode myNode=new ListNode(Integer.MAX_VALUE);
        Stack<ListNode> myStack=new Stack<ListNode>();
        myStack.push(myNode);
        for(;head!=null;head=head.next){
            while((myStack.peek().val)<head.val) myStack.pop();
            myStack.peek().next=head;
            myStack.push(head);
        }
        return myNode.next;
        //My old Time limit exceeded code :(
        /*
        if(head==null || head.next==null) return head;
        ListNode myNode=new ListNode(7);
        myNode.next=head;
        ListNode p=myNode;
        for(ListNode p1=head;p1!=null;p=p.next,p1=p1.next){
            for(ListNode p2=p1.next;p2!=null;){
                if((p1.val)<(p2.val)){
                    p.next=p1.next;
                    p1=p.next;
                }else{
                    p2=p2.next;
                }
            }
        }
        return myNode.next;
        */
    }
}