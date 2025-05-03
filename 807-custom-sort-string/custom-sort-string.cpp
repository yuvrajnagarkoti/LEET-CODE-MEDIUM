class Solution {
public:
    string customSortString(string order, string s)
    {
        vector <int> count(26,0);
        string ans;
        for(int i=0 ; i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        for(int i=0 ; i<order.length() ; i++)
        {
            while(count[order[i]-'a'] != 0)
            {
                ans = ans + order[i];
                count[order[i] - 'a']--;
            }
        }
        for(int i=0 ; i<26 ; i++)
        {
            while(count[i] != 0)
            {
                ans = ans + char(i+'a');
                count[i]--;
            }
        }
        return ans;
    }
};