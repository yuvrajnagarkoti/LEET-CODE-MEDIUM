class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int ch[26] = {0};
        if(s.length() != t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            ch[ s[i]-'a']++;
            ch[ t[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(ch[i] != 0)
                return false;
        }
        return true;
    }
};