class Solution
{
    public:
    static int ctoi(char c)
    {
        return c - '0';
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            vector<int> count(9,0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.') continue;
                int temp = ctoi(board[i][j])-1;
                if(count[temp] != 0)
                    return false;
                count[temp]++;
            }
        }

        for(int i=0;i<9;i++)
        {
            vector<int> count(9,0);
            for(int j=0;j<9;j++)
            {
                if(board[j][i] == '.') continue;
                int temp = ctoi(board[j][i])-1;
                if(count[temp] != 0)
                    return false;
                count[temp]++;
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