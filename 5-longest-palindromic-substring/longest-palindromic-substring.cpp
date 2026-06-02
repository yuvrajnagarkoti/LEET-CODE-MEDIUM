class Solution
{
public:

    void check(int left,int right,string s,string &ans)
    {
        int n = s.length();
        while(left >=0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        if(ans.size() < right-left-1 )
        {
            ans = s.substr(left+1,right-left-1);
        }
    }
    string longestPalindrome(string s)
    {   
        int n=s.length();
        if(n==1)
            return s;
        string ans = "";
        for(int i=0;i<n-1;i++)
        {
            check(i,i,s,ans);
            check(i,i+1,s,ans);
        }
        return ans; 
    }
};