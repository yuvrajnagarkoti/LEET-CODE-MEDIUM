class Solution
{
public:
    int palincheck(string s,int low,int high)
    {
        int i=low,j=high;
        while(i<j)
        {
            if(s[i++] != s[j--])
            {
                return 0;
            }
        }
        return high-low+1;
    }
    string longestPalindrome(string s)
    {
        int i,j;
        string ans;
        if(s.length() == 1) return s;
        for(i=0;i<s.length();i++)
        {
            for(j=i;j<s.length();j++)
            {
                if(s[i] != s[j]) continue;
                if(ans.length() < palincheck(s,i,j))
                    ans=s.substr(i,j-i+1);
            }
        }
        return ans;
    }
};