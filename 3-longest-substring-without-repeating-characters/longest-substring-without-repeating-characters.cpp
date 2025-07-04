class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int low=0,high=0,n=s.length();
        int m=0,c=0;
        map <char,int> mpp;
        while(low < n && high < n)
        {
            int ch = s[high];
            if( mpp.find(ch) == mpp.end() )
            {
                c++;
                mpp[ch]++;
                high++;
                if( m < c)
                {
                    m = c;
                }
            }
            else
            {
                mpp.clear();
                c=0;
                low++;
                high=low;
            }
        }

        return m;
    }
};