class Solution {
   public:
    bool dfs(int i, int j, int curr, vector<vector<char>>& b, int& row, int& col, string& word) {
        if (curr >= word.length()) {
            return true;
        }
        if (i < 0 or i >= row or j < 0 or j >= col or b[i][j] == '.' or b[i][j] != word[curr]) {
            return false;
        }

        char ch = b[i][j];
        b[i][j] = '.';

        bool left = dfs(i, j - 1, curr + 1, b, row, col, word);
        bool right = dfs(i, j + 1, curr + 1, b, row, col, word);
        bool top = dfs(i - 1, j, curr + 1, b, row, col, word);
        bool bottom = dfs(i + 1, j, curr + 1, b, row, col, word);

        b[i][j] = ch;

        return (left or right or top or bottom);
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool tempAns = dfs(i, j, 0, board, row, col, word);
                if (tempAns) return true;
            }
        }

        return false;
    }
};