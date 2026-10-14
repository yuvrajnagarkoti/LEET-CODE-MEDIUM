class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<pair<int,int>> p;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    p.push_back({i,j});
                }
            }
        }

        while( !p.empty())
        {
            int x=p.back().first;
            int y=p.back().second;
            for(int i=0;i<n;i++)
                matrix[i][y] = 0;
            for(int i=0;i<m;i++)
                matrix[x][i] = 0;

            p.pop_back();
        }
    }
};