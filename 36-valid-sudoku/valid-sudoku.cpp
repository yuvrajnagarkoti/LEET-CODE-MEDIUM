class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // Check rows and columns
        for(int i = 0; i < 9; i++)
        {
            vector<int> rowCount(9, 0);
            vector<int> colCount(9, 0);
            
            for(int j = 0; j < 9; j++)
            {
                // Check row
                if(board[i][j] != '.')
                {
                    int temp = board[i][j] - '0' - 1;
                    if(rowCount[temp] != 0) return false;
                    rowCount[temp]++;
                }
                // Check column
                if(board[j][i] != '.')
                {
                    int temp = board[j][i] - '0' - 1;
                    if(colCount[temp] != 0) return false;
                    colCount[temp]++;
                }
            }
        }

        // Check 3x3 sub-boxes
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                vector<int> count(9,0);
                for(int k = i; k < i + 3; k++)
                {
                    for(int l = j; l < j + 3; l++)
                    {
                        if(board[k][l] == '.') continue;
                        int temp = board[k][l] - '0' - 1;
                        if(count[temp] != 0) return false;
                        count[temp]++;
                    }
                }
            }
        }
        return true;
    }
};
