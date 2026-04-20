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
    void reorderList(ListNode* head)
    {
        ListNode *temp = head;
        stack<ListNode *> st;
        while(temp != NULL)
        {
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        int n=st.size();

        for(int i=0;i<n/2;i++)
        {
            ListNode *t = st.top();
            st.pop();
            ListNode *p = temp->next;
            temp->next = t;
            t->next = p;
            temp=p;
        }
        temp->next = NULL;
    }
};