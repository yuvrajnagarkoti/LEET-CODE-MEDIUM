class Solution
{
    public:
    vector<string> ans;

    bool isvalid(string curr)
    {
        int sum=0;
        for(int i=0;i<curr.length();i++)
        {
            if(curr[i] == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return false;    
        }
        if(sum == 0)
            return true;
        return false;
    }

    void solve(string &curr,int n)
    {
        if(curr.length() == n*2)
        {
            if(isvalid(curr))
                ans.push_back(curr);
            return;
        }
        int open=0,close=0;
        for(int i=0;i<curr.length();i++)
        {
            if(curr[i] == '(')
                open++;
            else
                close++;
        }
        if( open <= n)
        {
            curr.push_back('(');
            solve(curr,n);
            curr.pop_back();
        }
        if( close < open)
        {
            curr.push_back(')');
            solve(curr,n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string curr="";
        solve(curr,n);
        return ans;
    }
};