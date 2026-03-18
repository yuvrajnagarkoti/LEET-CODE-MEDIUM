class Solution
{
public:

    int count=0;
    void check(int i,int j,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != '1')
            return;
        
        if(grid[i][j] == '1')
        {
            grid[i][j] = '$';
            check(i+1,j,grid);
            check(i,j+1,grid);
            check(i-1,j,grid);
            check(i,j-1,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {   
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    check(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};