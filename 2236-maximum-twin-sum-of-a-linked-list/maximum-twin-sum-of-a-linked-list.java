class Solution {
    public int pairSum(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        // Reverse first half
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;

            ListNode next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }

        // prev = reversed first half
        // slow = second half
        int ans = 0;

        while(prev != null && slow != null)
        {
            ans = Math.max(ans, prev.val + slow.val);

            prev = prev.next;
            slow = slow.next;
        }

        return ans;
    }
}