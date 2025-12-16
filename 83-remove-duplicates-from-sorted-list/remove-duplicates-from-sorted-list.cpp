class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL)
            return head;

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while (temp2 != NULL)
        {
            if (temp1->val == temp2->val)
            {
                temp2 = temp2->next;
                temp1->next = temp2;
            }
            else
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};