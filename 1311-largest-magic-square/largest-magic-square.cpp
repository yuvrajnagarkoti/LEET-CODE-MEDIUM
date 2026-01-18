class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n, 0));
        vector<vector<int>> col(m, vector<int>(n, 0));

        // Row prefix sum
        for (int i = 0; i < m; i++)
        {
            row[i][0] = grid[i][0];
            for (int j = 1; j < n; j++)
                row[i][j] = row[i][j - 1] + grid[i][j];
        }

        // Column prefix sum
        for (int j = 0; j < n; j++)
        {
            col[0][j] = grid[0][j];
            for (int i = 1; i < m; i++)
                col[i][j] = col[i - 1][j] + grid[i][j];
        }

        for (int size = min(m, n); size >= 2; size--)
        {
            for (int i = 0; i + size - 1 < m; i++)
            {
                for (int j = 0; j + size - 1 < n; j++)
                {

                    int target = row[i][j + size - 1] - (j ? row[i][j - 1] : 0);
                    bool ok = true;

                    // Check rows
                    for (int r = i; r < i + size; r++)
                    {
                        int sum =
                            row[r][j + size - 1] - (j ? row[r][j - 1] : 0);
                        if (sum != target)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (!ok)
                        continue;

                    // Check columns
                    for (int c = j; c < j + size; c++)
                    {
                        int sum =
                            col[i + size - 1][c] - (i ? col[i - 1][c] : 0);
                        if (sum != target)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (!ok)
                        continue;

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int k = 0; k < size; k++)
                    {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + size - 1 - k];
                    }

                    if (d1 == target && d2 == target)
                        return size;
                }
            }
        }
        return 1;
    }
};
