class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack <pair<char,int>> stk;
        for(int i=0;i<s.length();i++)
        {
            if( stk.empty() || stk.top().first != s[i] )
            {
                stk.push({s[i],1});
            }
            else if(stk.top().first == s[i])
            {
                if(stk.top().second+1 == k)
                {
                    stk.pop();
                }
                else
                {
                    stk.top().second++;
                }
            }
        }

        string ans;
        while(!stk.empty())
        {
            char c = stk.top().first;
            int n = stk.top().second;
            while(n--)
            {
                ans.push_back(c);
            }
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};