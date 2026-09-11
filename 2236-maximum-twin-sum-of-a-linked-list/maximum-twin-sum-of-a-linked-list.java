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
    public int pairSum(ListNode head)
    {
        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=null;

        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            ListNode next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;       
        }
    
        fast = slow;
        slow = prev;
        int ans=0;
        while(fast != null && slow != null)
        {
            int t = fast.val+slow.val;
            if(ans < t)
                ans = t;

            slow=slow.next;
            fast=fast.next;
        }
        return ans;
    }
}