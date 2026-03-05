class Solution {
public:
    int dp[201][201];

    int solve(vector<vector<int>>& grid, int row, int col, int i, int j) {

        if(i == row - 1 && j == col - 1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == row - 1) {
            return dp[i][j] = grid[i][j] + solve(grid, row, col, i, j + 1);
        }

        if(j == col - 1) {
            return dp[i][j] = grid[i][j] + solve(grid, row, col, i + 1, j);
        }

        return dp[i][j] = grid[i][j] + min(
            solve(grid, row, col, i + 1, j),
            solve(grid, row, col, i, j + 1)
        );
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(grid, n, m, 0, 0);
    }
};