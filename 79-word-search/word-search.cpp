class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int rows, cols, len;

    bool find(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx >= len) return true;

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, word, new_i, new_j, idx + 1)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        len = word.length();

        if (rows * cols < len) return false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && find(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};