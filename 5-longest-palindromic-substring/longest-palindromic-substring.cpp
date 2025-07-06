class Solution
{
public:
    static bool checkpalin(const string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        int max_len = 0;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= i; j--)
            {
                if (s[i] == s[j] && (j - i + 1) > max_len && checkpalin(s, i, j))
                {
                    ans = s.substr(i, j - i + 1);
                    max_len = j - i + 1;
                    break;  // No need to check smaller substrings for this i
                }
            }
        }
        return ans;
    }
};
