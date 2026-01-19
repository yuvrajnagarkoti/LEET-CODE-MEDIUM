class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();

        // 2D prefix sum
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                ps[i][j] = mat[i-1][j-1]
                         + ps[i-1][j]
                         + ps[i][j-1]
                         - ps[i-1][j-1];
            }
        }

        for(int s = min(m, n); s >= 1; s--)
        {
            for(int i = 0; i + s <= m; i++)
            {
                for(int j = 0; j + s <= n; j++)
                {
                    int sum = ps[i+s][j+s]
                            - ps[i][j+s]
                            - ps[i+s][j]
                            + ps[i][j];

                    if(sum <= threshold)
                        return s;
                }
            }
        }

        return 0;
    }
};
