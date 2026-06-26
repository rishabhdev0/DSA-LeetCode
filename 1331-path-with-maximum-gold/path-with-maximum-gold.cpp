class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int backtracking(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0;
        }

        int originalGold = grid[i][j];
        grid[i][j] = 0;

        int gold = 0;

        for (auto &d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];

            gold = max(gold, backtracking(grid, i_, j_, n, m));
        }

        grid[i][j] = originalGold;

        return originalGold + gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, backtracking(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};