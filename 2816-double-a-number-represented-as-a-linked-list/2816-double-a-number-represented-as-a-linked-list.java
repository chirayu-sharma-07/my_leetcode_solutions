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
    public ListNode reverseLinkedList(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode p1=null;
        ListNode p2=head;
        ListNode p3=head.next;
        while(p3!=null){
            p2.next=p1;
            p1=p2;
            p2=p3;
            p3=p3.next;
        }
        p2.next=p1;
        return p2;
    }
    public ListNode doubleIt(ListNode head) {
        ListNode myList=new ListNode(7);
        myList.next=reverseLinkedList(head);
        ListNode p1=myList;
        int remaining=0;
        while(p1.next!=null){
            int val=p1.next.val;
            val=val*2;
            val+=remaining;
            remaining=0;
            if(val>9){
                val=val%10;
                remaining=1;
            }
            p1.next.val=val;
            p1=p1.next;
        }
        if(remaining==1){
            ListNode extraNode=new ListNode(1);
            extraNode.next=null;
            p1.next=extraNode;
        }
        p1=reverseLinkedList(myList.next);
        return p1;
    }
}