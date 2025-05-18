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
    int gcd(int n1,int n2)
    {
        int ans =1;
        int m= min(n1,n2);
        for(int i=2; i<=m ;i++)
        {
            if(n1%i == 0 && n2%i == 0)
            {
                ans=i;
            }
        }
        return ans;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode*temp = head;
        while(temp->next != NULL )
        {
            int g =  gcd(temp->val , temp->next->val);
            ListNode* a = new ListNode(g);  
            a->next = temp->next;
            temp->next = a;
            temp=temp->next->next;
        }
        return head;
    }
};