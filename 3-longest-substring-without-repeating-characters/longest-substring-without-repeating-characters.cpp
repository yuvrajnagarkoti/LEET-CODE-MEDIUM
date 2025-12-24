class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> mpp;
        int low=0,count=0;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
            if( mpp[s[i]] == 2)
            {
                while(mpp[s[i]] == 2)
                {
                    mpp[s[low]]--;
                    if(mpp[s[low]] == 0)
                        mpp.erase(s[low]);
                    low++;
                }
            }
            count=max(count,i-low+1);
        }
        return count;
    }
};