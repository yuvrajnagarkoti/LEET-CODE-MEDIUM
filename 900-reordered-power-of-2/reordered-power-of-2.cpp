class Solution
{
    public:
    static string sorteddig(int n)
    {
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n)
    {
        string s=sorteddig(n);
        int ans=1;
        for(int i=0;i<=29;i++)
        {
            if(sorteddig(ans) == s)
                return true;
            ans=ans*2;
        }
        return false;
    }
};