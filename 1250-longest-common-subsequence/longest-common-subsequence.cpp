class Solution
{
    public:
    int count[1001][1001];
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(count,0,sizeof(count));
        int n=text1.length(),m=text2.length();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    count[i][j] = count[i-1][j-1] + 1;
                }
                else
                {
                    count[i][j] = max(count[i-1][j],count[i][j-1]);
                }
            }
        }   
        return count[n][m]; 
    }
};