class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            char current = s[end];
            if (lastSeen.count(current) && lastSeen[current] >= start)
            {
                start = lastSeen[current] + 1;
            }
            lastSeen[current] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
