class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int time = 0;

        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int d = 0; d < 4; d++)
            {
                int r = i + row[d];
                int c = j + col[d];
                if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                {
                    q.push({{r, c}, t + 1});
                    grid[r][c] = 2;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};
