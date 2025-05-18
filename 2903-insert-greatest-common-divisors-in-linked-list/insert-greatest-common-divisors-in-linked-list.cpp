/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        if(!head and !head->next)
        {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr)
        {
            int res = gcd(prev->val,curr->val);
            ListNode* node = new ListNode(res);
            ListNode *temp = curr->next;
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};