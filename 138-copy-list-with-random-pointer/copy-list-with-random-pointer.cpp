class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
            return NULL;

        vector<int> nums;
        Node *temp = head;
        int i = 0;

        map<Node*, int> idx;
        map<int, Node*> add;
        map<int, int> rand;

        while(temp != NULL)
        {
            nums.push_back(temp->val);
            idx[temp] = i;
            add[i++] = temp;
            temp = temp->next;
        }

        temp = head;
        i = 0;
        while(temp != NULL)
        {
            if(temp->random == NULL)
                rand[i++] = -1;
            else
                rand[i++] = idx[temp->random];

            temp = temp->next; 
        }
        Node *ans = new Node(nums[0]);
        Node *t = ans;

        map<int, Node*> idx1;
        idx1[0] = ans;

        for(int i = 1; i < nums.size(); i++)
        {
            t->next = new Node(nums[i]);
            t = t->next;
            idx1[i] = t;
        }

        t = ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(rand[i] == -1)
                t->random = NULL;
            else
                t->random = idx1[rand[i]];

            t = t->next;
        }

        return ans;
    }
};