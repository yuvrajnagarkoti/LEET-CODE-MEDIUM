class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> count(26, 0);
        for (char c : s)
        {
            count[c - 'a']++;
        }
        string res;
        for (char c : order)
        {
            res.append(count[c - 'a'], c);
            count[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i)
        {
            res.append(count[i], 'a' + i);
        }
        return res;
    }
};