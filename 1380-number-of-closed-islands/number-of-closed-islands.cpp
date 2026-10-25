class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;
    int n;
    int m;

    bool solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;

        if (grid[i][j] == 1) return true;

        grid[i][j] = 1;
        bool closed = true;

        for (auto direction : dir) {
            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if (!solve(grid, new_i, new_j)) {
                closed = false;
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (solve(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};