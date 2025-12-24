class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1);  // ASCII
        int low = 0, ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (last[s[i]] >= low)
                low = last[s[i]] + 1;

            last[s[i]] = i;
            ans = max(ans, i - low + 1);
        }
        return ans;
    }
};