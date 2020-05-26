class Solution {
public:
    int rows;
    int columns;
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)   return;
        rows = board.size();
        columns = board[0].size();
        for(int i = 0; i < rows; i++){
            dfs(board, i, 0);
            dfs(board, i, columns - 1);
        }
        for(int i = 0; i < columns; i++){
            dfs(board, 0, i);
            dfs(board, rows - 1, i);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                if(board[i][j] == '-')  board[i][j] = 'O';
            }
        }
        return;
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= columns || board[i][j] != 'O')   return;
        board[i][j] = '-';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
        return;
    }
};