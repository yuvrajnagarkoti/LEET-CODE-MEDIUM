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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return head; // handle empty list
        vector<int> temp;
        ListNode* t = head;

        while (t != nullptr)
        {
            temp.push_back(t->val);
            t = t->next;
        }
        int n = temp.size();
        k = k % n;
        if (k == 0) return head; // no rotation needed

        t = head;
        for (int i = n - k; i < n; i++)
        {
            t->val = temp[i];
            t = t->next;
        }

        for (int i = 0; i < n - k; i++)
        {
            t->val = temp[i];
            t = t->next;
        }

        return head;
    }
};