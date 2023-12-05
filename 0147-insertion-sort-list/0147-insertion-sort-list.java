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
    private ListNode MID(ListNode head){
        if(head==null || head.next==null || head.next.next==null) return head;
        ListNode slow=head;
        ListNode fast=slow;
        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    private ListNode sort(ListNode left,ListNode right){
        if(left==null || right==null){
            return (left==null)?right:left;
        }
        ListNode newNode=new ListNode(7);
        ListNode curr=newNode;
        while(left!=null && right!=null){
            if(left.val<right.val){
                curr.next=left;
                left=left.next;
            }else{
                curr.next=right;
                right=right.next;
            }
            curr=curr.next;
        }
        curr.next=(left==null)?right:left;
        return newNode.next;
    }
    public ListNode insertionSortList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode mid=MID(head);
        ListNode newNode=mid.next;
        mid.next=null;
        ListNode left_list=insertionSortList(head);
        ListNode right_list=insertionSortList(newNode);
        return sort(left_list,right_list);
    }
}