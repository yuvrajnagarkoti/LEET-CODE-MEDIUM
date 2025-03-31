class Solution
{
public:
    void zero(vector<vector<int>>& temp, int k1, int k2)
    {
        int rows = temp.size();
        int cols = temp[0].size();
        for (int i = 0; i < cols; i++)
        {
            temp[k1][i] = 0;
        }
        for (int i = 0; i < rows; i++)
        {
            temp[i][k2] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> temp = matrix;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zero(temp, i, j);
                }
            }
        }
        matrix = temp;
    }
};
