class Solution
{
public:
    int dp[201][201];

    int rec(int x, int y, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(x >= m || y >= n)
            return INT_MAX;

        if(x == m-1 && y == n-1)
            return grid[x][y];

        if(dp[x][y] != -1)
            return dp[x][y];

        int down  = rec(x+1, y, grid);
        int right = rec(x, y+1, grid);

        return dp[x][y] = grid[x][y] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, grid);
    }
};