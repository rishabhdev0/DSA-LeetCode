class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                bool isBorder =
                    i == 0 ||
                    j == 0 ||
                    i == n - 1 ||
                    j == m - 1;

                if (isBorder && board[i][j] == 'O') {
                    que.push({i, j});
                    board[i][j] = '#';
                }
            }
        }

        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();

            for (auto dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (
                    newRow >= 0 &&
                    newCol >= 0 &&
                    newRow < n &&
                    newCol < m &&
                    board[newRow][newCol] == 'O'
                ) {
                    board[newRow][newCol] = '#';
                    que.push({newRow, newCol});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};