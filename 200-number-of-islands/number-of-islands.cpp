class Solution
{
    public:
    void findland(vector<vector<char>> &grid,int i,int j,vector<vector<int>> &vis)
    {
        int n=grid.size(),m=grid[0].size();
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1 || grid[i][j]=='0') 
            return;
        
        vis[i][j] = 1;
        
        findland(grid,i,j+1,vis);
        findland(grid,i,j-1,vis);
        findland(grid,i+1,j,vis);
        findland(grid,i-1,j,vis);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1')
                {
                    ans++;
                    findland(grid,i,j,vis);
                }
            }
        }

        return ans;
    }
};