class Solution
{
public:
    int n,m;
    int area=0;

    void island(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        area++;
        island(i+1,j,grid);
        island(i-1,j,grid);
        island(i,j+1,grid);
        island(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                area=0;
                if(grid[i][j] == 1)
                {
                    island(i,j,grid);
                    ans = max(ans,area);
                }
            }
        }

        return ans;
    }
};