class Solution {
private:
    pair<int,int> getCoord(int num, int n) {
        int rowFromBottom = (num - 1) / n;
        int row = n - 1 - rowFromBottom;

        int col = (num - 1) % n;
        if ((n - row) % 2 == 0) {
            col = n - 1 - col;
        }

        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return steps;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > n * n) break;

                    auto [r, c] = getCoord(next, n);
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
