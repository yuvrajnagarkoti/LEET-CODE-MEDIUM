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
        stack<ListNode *> st;
        ListNode *temp = head;
        while(temp != NULL)
        {
            st.push(temp);
            temp=temp->next;
        }

        while(n>0)
        {
            st.pop();
            n--;
        }

        if(st.empty())
        {
            head=head->next;
        }
        else
        {
            st.top()->next = st.top()->next->next;
        }
        return head;
    }
};