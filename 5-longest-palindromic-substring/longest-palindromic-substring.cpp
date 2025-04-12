class Solution
{
public:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            int len = right - left + 1;
            if (len > maxLen)
            {
                maxLen = len;
                start = left;
            }
            --left;
            ++right;
        }
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n <= 1) return s;
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; ++i)
        {
            // Odd length palindrome
            expandAroundCenter(s, i, i, start, maxLen);
            // Even length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
};
