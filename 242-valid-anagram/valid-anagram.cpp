class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int i,c1[26]={0},c2[26]={0};
        if(s.length() != t.length()) return false;
        for(i=0;i<s.length();i++)
        {
            c1[s[i]-'a']++;
            c2[t[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            if(c1[i] != c2[i])
            {
                return false;
            }
        }
        return true;
    }
};