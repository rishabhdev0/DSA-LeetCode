class Solution {
public:
    vector<vector<int>> direction = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> que;

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!que.empty() && fresh > 0) {
            int size = que.size();

            while (size--) {
                auto [i, j] = que.front();
                que.pop();

                for (auto dir : direction) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (
                        new_i >= 0 &&
                        new_j >= 0 &&
                        new_i < n &&
                        new_j < m &&
                        grid[new_i][new_j] == 1
                    ) {
                        grid[new_i][new_j] = 2;
                        fresh--;

                        que.push({new_i, new_j});
                    }
                }
            }

            minutes++;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};