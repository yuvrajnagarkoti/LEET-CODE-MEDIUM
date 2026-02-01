class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<int> prev(n), curr(n);

        // base case
        for (int j = 0; j < n; j++)
            prev[j] = matrix[0][j];

        // build dp
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = prev[j];
                int upLeft = (j > 0) ? prev[j - 1] : INT_MAX;
                int upRight = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({up, upLeft, upRight});
            }
            prev = curr; // move to next row
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, prev[j]);

        return ans;
    }
};
