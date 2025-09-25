class Solution {
private:
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;

        int originalGold = grid[i][j];
        grid[i][j] = 0; // mark as visited
        int maxGold = 0;

        for (const vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            maxGold = max(maxGold, dfs(grid, new_i, new_j, n, m));
        }

        grid[i][j] = originalGold; // backtrack
        return originalGold + maxGold; 
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};