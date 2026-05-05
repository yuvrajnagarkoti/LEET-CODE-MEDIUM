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
        if(k==0 || head == NULL)
            return head;
        ListNode *fast = head,*slow = head;
        ListNode *temp = head;
        int count=0;
        while( temp != NULL)
        {
            temp=temp->next;
            count++;
        }
        k = k % count;
        while(k--)
        {
            fast = fast -> next;
        }

        while(fast->next != NULL && slow->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        temp = slow->next;
        slow->next = NULL;

        return temp;
    }
};