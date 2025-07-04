class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0) return 0;

        int low = 0, high = 0, n = s.length();
        int max_len = 0;
        map<char, int> mpp;

        while (high < n)
        {
            char ch = s[high];

            // If duplicate found, shrink window from left
            if (mpp.find(ch) != mpp.end())
            {
                mpp.erase(s[low]);
                low++;
            }

            else
            {
                mpp[ch] = 1;
                max_len = max(max_len, high - low + 1);
                high++;
            }
        }
        return max_len;
    }
};
