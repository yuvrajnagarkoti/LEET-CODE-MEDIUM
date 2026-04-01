class Solution
{
    public:

    int minesaround(vector<vector<char>> &board,int i,int j)
    {
        int m=board.size(),n=board[0].size();
        if(i>=m || j>=n || i<0 || j<0)
            return 0;
        if(board[i][j] == 'M')
            return 1;
        return 0;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,int i,int j)
    {
        int m=board.size(),n=board[0].size();
        if(i>=m || j>=n || i<0 || j<0 || vis[i][j] == 1 || board[i][j] == 'M')
            return;
        
        vis[i][j] = 1;
        int count=0;
        count += minesaround(board,i+1,j);
        count += minesaround(board,i,j+1);
        count += minesaround(board,i-1,j);
        count += minesaround(board,i,j-1);
        count += minesaround(board,i+1,j+1);
        count += minesaround(board,i-1,j-1);
        count += minesaround(board,i+1,j-1);
        count += minesaround(board,i-1,j+1);
        if(count > 0)
        {
            board[i][j] = count+48;
        }
        if(count == 0)
        {
            board[i][j] = 'B';
            dfs(board,vis,i+1,j);
            dfs(board,vis,i,j+1);
            dfs(board,vis,i-1,j);
            dfs(board,vis,i,j-1);
            dfs(board,vis,i+1,j+1);
            dfs(board,vis,i-1,j-1);
            dfs(board,vis,i+1,j-1);
            dfs(board,vis,i-1,j+1);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        int i=click[0],j=click[1];
        int m=board.size(),n=board[0].size();
        if(board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return board;
        }
        vector<vector<int>> vis(m,vector<int> (n,0));
        dfs(board,vis,i,j);

        return board;
    }
};