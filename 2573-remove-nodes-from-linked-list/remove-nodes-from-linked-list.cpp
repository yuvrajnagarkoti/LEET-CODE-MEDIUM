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
    ListNode* removeNodes(ListNode* head)
    {
        stack<int> stk;
        ListNode *temp=head;
        while(temp != NULL)
        {
            stk.push(temp->val);
            temp=temp->next;
        }
        int rightm = INT_MIN;
        vector<int> ans;
        while(!stk.empty())
        {
            if(stk.top() >= rightm)
            {
                ans.push_back(stk.top());
            }
            rightm=max(rightm,stk.top());
            stk.pop();
        }
        temp=head;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++)
        {
            temp->val=ans[i];
            temp=temp->next;
        }
        temp->val=ans[ans.size()-1];
        temp->next=NULL;
        return head;
    }
};