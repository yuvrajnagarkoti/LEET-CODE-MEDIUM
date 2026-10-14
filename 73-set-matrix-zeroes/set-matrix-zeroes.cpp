class Solution {
public:
    void setZeroes(vector<vector<int>>& mat)
    {
        int n=mat.size(),m=mat[0].size();
        bool first = false,second = false;

        for(int i=0;i<n;i++)
        {
            if(mat[i][0]==0)
                first=true;
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j] == 0)
                second=true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
        if(first)
        {
            for(int i=0;i<n;i++)
            {
                mat[i][0] = 0;
            }
        }
        if(second)
        {
            for(int j=0;j<m;j++)
            {
                mat[0][j] = 0;
            }
        }
        return;
    }
};