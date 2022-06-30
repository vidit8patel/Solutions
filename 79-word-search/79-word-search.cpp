class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word)
    {
        if(word.length() == 0)
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = word[0];
        string s = word.substr(1);
        board[i][j] = '-1';
        bool check =dfs(board, i+1, j, s) ||
                    dfs(board, i-1, j, s) ||
                    dfs(board, i, j+1, s) ||
                    dfs(board, i, j-1, s);
        board[i][j] = c;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[0].size(); j++)
            {
                if(dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
};