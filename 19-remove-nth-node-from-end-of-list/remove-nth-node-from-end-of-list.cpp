class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *p1 = head, *p2 = head;
        int i = 0;
        while (i < n && p2 != NULL)
        {
            p2 = p2->next;
            i++;
        }
        if (p2 == NULL)
        {
            head = head->next;
            return head;
        }
        p2 = p2->next;
        while (p2 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};
