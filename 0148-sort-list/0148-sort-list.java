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
    private ListNode Mid(ListNode head){
        ListNode slow=head;
        ListNode fast=head;
        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    private ListNode mySort(ListNode firstHalf,ListNode secondHalf){
        if(firstHalf==null || secondHalf==null){
            return (firstHalf==null)?secondHalf:firstHalf;
        }
        ListNode myNode=new ListNode(7);
        ListNode curr=myNode;
        while(firstHalf!=null && secondHalf!=null){
            if(firstHalf.val<secondHalf.val){
                curr.next=firstHalf;
                firstHalf=firstHalf.next;
            }else{
                curr.next=secondHalf;
                secondHalf=secondHalf.next;
            }
            curr=curr.next;
        }
        if(firstHalf!=null || secondHalf!=null){
            curr.next=(firstHalf!=null)?firstHalf:secondHalf;
        }
        return myNode.next;
    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode mid=Mid(head);
        ListNode newHead=mid.next;
        mid.next=null;
        ListNode firstHalf=sortList(head);
        ListNode secondHalf=sortList(newHead);
        return mySort(firstHalf,secondHalf);
    }
}