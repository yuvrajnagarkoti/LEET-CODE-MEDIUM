
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int len = 0, cnt = 0;
        ListNode* temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        if (n == len)
            return head->next;
        
        cnt = len - n;
        temp = NULL;
        ListNode* front = head;
        for (int i = 0; i < cnt; i++)
        {
            temp = front;
            front = front->next;
        }
        temp->next = front->next;
        return head;
    }
};