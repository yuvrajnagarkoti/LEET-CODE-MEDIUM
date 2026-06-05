class Solution
{
public:

    void multibfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,queue<pair<int,int>> &q)
    {
        int n=grid.size(),m=grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] != 1)
            return;

        vis[i][j] = 1;
        grid[i][j] = 2;
        q.push({i,j});
    }

    bool check(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return false;
            }
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int count=0;
        while(!q.empty())
        {
            if(check(grid))
                return count;

            int limit=q.size();
            count++;
            while(limit--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                multibfs(i,j+1,grid,vis,q);
                multibfs(i,j-1,grid,vis,q);
                multibfs(i+1,j,grid,vis,q);
                multibfs(i-1,j,grid,vis,q);
            }
        }

        return check(grid) ? count : -1;
    }
};