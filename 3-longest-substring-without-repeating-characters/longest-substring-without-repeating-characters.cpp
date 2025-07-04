class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int i,j,m=0;
        for(i=0;i<s.length();i++)
        {
            unordered_map <char,int> mpp;
            int c=0;
            for(j=i;j<s.length();j++)
            {
                int ch = s[j]-'a';
                if( mpp.find(ch) == mpp.end())
                {
                    mpp[ch]++;
                    c++;
                }
                else 
                    break;
            }

            if(c>m)
                m=c;
        }
        return m;
    }
};