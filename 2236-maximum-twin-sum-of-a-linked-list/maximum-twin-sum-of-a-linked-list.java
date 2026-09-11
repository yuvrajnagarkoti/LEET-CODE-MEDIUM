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
        ArrayList<Integer> arr = new ArrayList<>();
        ListNode temp = head;
        while(temp != null)
        {
            arr.add(temp.val);
            temp = temp.next;
        }
        int i=0,j=arr.size()-1;
        int ans=0;
        while(i<j)
        {
            int t=arr.get(i)+arr.get(j);
            if(ans < t)
                ans = t;

            i++;
            j--;
        }

        return ans;
    }
}