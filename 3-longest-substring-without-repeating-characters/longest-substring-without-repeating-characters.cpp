class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            vector<char> v;
            for(int j=i;j<s.length();j++)
            {
                if (find(v.begin(), v.end(), s[j]) == v.end())
                {
                    v.push_back(s[j]);
                }
                else
                {
                    break;
                }
                ans = max(ans, (int)v.size());
            }
        }
        return ans;
    }
};