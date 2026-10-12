class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty() && fresh > 0)
        {
            int sz = q.size();
            time++;

            while (sz--)
            {
                auto [i, j] = q.front();
                q.pop();

                for (auto [dx, dy] : dir)
                {
                    int x = i + dx;
                    int y = j + dy;

                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;

                    if (grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};