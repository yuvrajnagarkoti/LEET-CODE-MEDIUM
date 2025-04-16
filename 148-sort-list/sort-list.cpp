class Solution
{
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};
