class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        int l=0;
        vector<bool> seen(256, false);

        int ans = 0;
        for(int r=0; r<len; r++)
        {
            if(seen[s[r]] == false)
            {
                seen[s[r]] = true;
            }
            else
            {
                while(s[l] != s[r])
                {
                    seen[s[l]] = false;
                    l++;
                }
                l++;
                if(l>=len) break;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};