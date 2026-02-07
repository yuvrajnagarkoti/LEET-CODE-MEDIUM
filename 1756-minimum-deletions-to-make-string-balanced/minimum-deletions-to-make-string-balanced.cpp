class Solution {
public:
    int minimumDeletions(string s)
    {
        stack<char> stk;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty())
                stk.push(s[i]);
            else
            {
                char temp = stk.top();
                if(temp == 'b' && s[i] == 'a')
                {
                    stk.pop();
                    ans++;
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        return ans;
    }
};