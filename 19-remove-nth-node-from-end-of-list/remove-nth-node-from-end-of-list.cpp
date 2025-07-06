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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp = head;
        int count = 0;

        // Count total nodes
        while (temp != NULL) 
        {
            count++;
            temp = temp->next;
        }

        // If we need to remove head node
        if (n == count) 
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Find the node before the one to remove
        temp = head;
        int stop = count - n - 1;
        while (stop > 0) 
        {
            temp = temp->next;
            stop--;
        }

        // Delete target node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
