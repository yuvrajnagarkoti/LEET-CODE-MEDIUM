class Solution
{
    public:
    static int ctoi(char c)
    {
        return c - '0';
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            vector<int> rowCount(9, 0);
            vector<int> colCount(9, 0);

            for(int j = 0; j < 9; j++)
            {
                // Check row
                if(board[i][j] != '.')
                {
                    int temp = ctoi(board[i][j]) - 1;
                    if(rowCount[temp] != 0) return false;
                    rowCount[temp]++;
                }
                // Check column
                if(board[j][i] != '.')
                {
                    int temp = ctoi(board[j][i]) - 1;
                    if(colCount[temp] != 0) return false;
                    colCount[temp]++;
                }
            }
        }
        
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                vector<int> count(9,0);
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l] == '.') continue;
                        int temp = ctoi(board[k][l])-1;
                        if(count[temp] != 0)
                            return false;
                        count[temp]++;
                    }
                }
            }
        }
        return true;
    }
};