class Solution
{
public:
    int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        int n = matrix.size();

        // out of bounds
        if (i >= n || j < 0 || j >= n)
            return 1000000000; // INF

        // last row
        if (i == n - 1)
            return matrix[i][j];

        // memoized
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int left  = rec(i + 1, j - 1, matrix, dp);
        int down  = rec(i + 1, j,     matrix, dp);
        int right = rec(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, rec(0, j, matrix, dp));
        }
        return ans;
    }
};
