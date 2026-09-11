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
        ArrayList<Integer> arr= new ArrayList<>();

        while(fast != null && fast.next != null)
        {
            arr.add(slow.val);
            slow=slow.next;
            fast=fast.next.next;
        }
        int i=arr.size()-1;
        int ans=0;
        while(i>=0)
        {

            int temp=arr.get(i)+slow.val;
            slow = slow.next;
            i--;

            if(ans < temp)
                ans=temp;
        }

        return ans;
    }
}