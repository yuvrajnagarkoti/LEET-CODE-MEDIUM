class Solution {
public:
    int minimumDeletions(string s)
    {
        int n=s.length();
        vector<int> leftb(n,0);
        vector<int> righta(n,0);

        for(int i=1;i<n;i++)
        {
            leftb[i] = leftb[i-1];
            if(s[i-1] == 'b')
                leftb[i]++;
        }

        for(int i=n-2;i>=0;i--)
        {
            righta[i] = righta[i+1];
            if(s[i+1] == 'a')
                righta[i]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans = min(ans,(righta[i]+leftb[i]) );
        }
        return ans;
    }
};