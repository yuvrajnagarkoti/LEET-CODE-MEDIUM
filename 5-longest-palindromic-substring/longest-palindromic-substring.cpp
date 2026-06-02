class Solution
{
public:
    void check(int left, int right, string &s, string &ans)
    {
        int n = s.length();

        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        int len = right - left - 1;   // actual palindrome length

        if(len > ans.size())
        {
            ans = s.substr(left + 1, len);
        }
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            check(i, i, s, ans);       // odd length
            check(i, i + 1, s, ans);   // even length
        }

        return ans;
    }
};