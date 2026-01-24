class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int bup[101][101]={-1};
        for(int i=0;i<101;i++)
        {
            bup[i][0]=1;
            bup[0][i]=1;
        }
        bup[0][0] = 1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                bup[i][j] = bup[i][j-1] + bup[i-1][j];
            }
        }
        return bup[m-1][n-1];
    }
};