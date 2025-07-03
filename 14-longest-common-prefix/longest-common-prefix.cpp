class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = strs[0];
        for (auto str : strs)
        {
            int i=0, j=0;
            while (i < str.length() && j < ans.length())
            {
                if (str[i] != ans[j])
                {
                    break;
                }
                i++;
                j++;
            }
            ans.erase(j);
            //if (ans.empty()) break;
        }
        return ans;
    }
};
