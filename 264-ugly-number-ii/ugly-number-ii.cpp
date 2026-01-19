class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;

        int n2 = 0, n3 = 0, n5 = 0;

        for(int i = 1; i < n; i++)
        {
            int next2 = dp[n2] * 2;
            int next3 = dp[n3] * 3;
            int next5 = dp[n5] * 5;
            dp[i] = min(next2, min(next3, next5));

            if(dp[i] == next2) n2++;
            if(dp[i] == next3) n3++;
            if(dp[i] == next5) n5++;
        }

        return dp[n-1];
    }
};