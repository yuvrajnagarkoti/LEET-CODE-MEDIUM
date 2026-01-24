class Solution
{
public:
    int dp[101][101] = {-1};

    int rec(int x,int y,vector<vector<int>>& obstacleGrid)
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(x >= m || y >= n || obstacleGrid[x][y] == 1)
            return 0;

        if( x==m-1 && y==n-1)
            return 1;
        
        if( dp[x][y] != -1)
            return dp[x][y];
        
        int left = rec(x+1,y,obstacleGrid);
        int right = rec(x,y+1,obstacleGrid);
        
        return dp[x][y] = left+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,obstacleGrid); // x,y,obstacle
    }
};