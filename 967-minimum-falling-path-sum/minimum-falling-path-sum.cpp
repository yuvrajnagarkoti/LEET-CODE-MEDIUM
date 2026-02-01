class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case: first row
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        // build dp table
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int upLeft = INT_MAX;
                int upRight = INT_MAX;
                int up = dp[i-1][j];
                if(j>0)
                    upLeft = dp[i-1][j-1];
                if(j<n-1)
                    upRight = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min({up, upLeft, upRight});
            }
        }

        // answer = min in last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[n-1][j]);

        return ans;
    }
};
