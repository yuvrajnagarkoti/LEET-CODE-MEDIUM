struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // Create a dummy node to simplify edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = dummy;
    int carry = 0;
    // Traverse both lists while there are digits to add
    while (l1 || l2 || carry)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10; // Extract carry
        sum = sum % 10;   // Extract last digit
        // Create a new node for the sum digit
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = sum;
        curr->next = NULL;
    }
    // Return the actual head (skipping dummy node)
    struct ListNode* result = dummy->next;
    free(dummy); // Free dummy node to avoid memory leak
    return result;
}
