class Solution
{
public:
    int rec(int i,int j,vector<vector<char>> &matrix,vector<vector<int>> &dp)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if( i>=m || j>= n)
            return 0;
        if( matrix[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right=rec(i,j+1,matrix,dp);
        int down=rec(i+1,j,matrix,dp);
        int diag=rec(i+1,j+1,matrix,dp);

        return dp[i][j] = 1 + min( {right,down,diag} );
    }

    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                {
                    ans = max(ans,rec(i,j,matrix,dp));
                }
            }
        }
        return ans*ans;
    }
};