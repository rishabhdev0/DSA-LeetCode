class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    int dp[501][501];

    pair<int, int> move(vector<vector<int>>& grid, int i, int j, int dir) {

        if (dir == 0) j++;  // Right
        else i++;           // Down

        while (i < m && j < n && grid[i][j] == 1) {

            if (dir == 0) {
                i++;       // Right -> Down
                dir = 1;
            }
            else {
                j++;       // Down -> Right
                dir = 0;
            }
        }

        if (i >= m || j >= n) {
            return {-1, -1};
        }

        return {i, j};
    }

    int solve(vector<vector<int>>& grid, int i, int j) {

        if (i == m - 1 && j == n - 1) return 1;

        if (i >= m || j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long count = 0;

        // Move right
        auto [x1, y1] = move(grid, i, j, 0);

        if (x1 != -1) {
            count = (count + solve(grid, x1, y1)) % MOD;
        }

        // Move down
        auto [x2, y2] = move(grid, i, j, 1);

        if (x2 != -1) {
            count = (count + solve(grid, x2, y2)) % MOD;
        }

        return dp[i][j] = count;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0);
    }
};