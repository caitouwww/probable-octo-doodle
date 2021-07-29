class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(dfs(board,visited,i,j,word,0))return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,string& word,int cur){
        /*if(i>=board.size()||j>=board[0].size())return false;
        if(visited[i][j]||board[i][j]!=word[cur])return false;*/
        if(cur==word.size())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||word[cur]!=board[i][j])return false;
        //visited[i][j] = true;
        if(visited[i][j]==false){
            visited[i][j] = true;
            if(dfs(board,visited,i+1,j,word,cur+1)||dfs(board,visited,i-1,j,word,cur+1)||dfs(board,visited,i,j+1,word,cur+1)||dfs(board,visited,i,j-1,word,cur+1))return true;
            visited[i][j] = false;
        }
        return false;
    }
};
