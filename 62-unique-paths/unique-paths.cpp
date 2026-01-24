class Solution
{
    public:
    int dp[101][101] = {-1};
    int rec(int x,int y,int m,int n)
    {
        if(x==m-1 && y==n-1)
            return 1;
        if(x == m)
            return 0;
        if(y == n)
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int left = rec(x+1,y,m,n);
        int right = rec(x,y+1,m,n);
        return dp[x][y] = left+right;
    }
    int uniquePaths(int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,m,n); //x=0,y=0,m,n; 
    }
};