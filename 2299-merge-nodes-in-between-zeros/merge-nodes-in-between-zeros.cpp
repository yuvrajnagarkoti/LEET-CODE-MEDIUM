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
public:
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* curr = head->next;
        ListNode* sumNode = head;
        ListNode* lastValid = nullptr;
        int sum = 0;

        while (curr != nullptr)
        {
            if (curr->val == 0)
            {
                sumNode->val = sum;
                sum = 0;
                lastValid = sumNode;
                sumNode = sumNode->next;
            }
            else
            {
                sum += curr->val;
            }
            curr = curr->next;
        }
        lastValid->next = nullptr;
        return head;
    }
};
