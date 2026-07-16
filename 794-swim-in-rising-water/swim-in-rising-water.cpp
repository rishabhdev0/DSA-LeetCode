class Solution {
public:
    vector<vector<int>> direction = {
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 0}
    };

    int n, m;

    void dfs(int i, int j, int node,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited) {

        visited[i][j] = 1;

        for (auto dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < n &&
                new_j >= 0 && new_j < m &&
                visited[new_i][new_j] == 0 &&
                grid[new_i][new_j] <= node) {

                dfs(new_i, new_j, node, grid, visited);
            }
        }
    }

    bool canSwim(int node, vector<vector<int>>& grid) {
        if (grid[0][0] > node) {
            return false;
        }

        vector<vector<int>> visited(n, vector<int>(m, 0));

        dfs(0, 0, node, grid, visited);

        return visited[n - 1][m - 1];
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int low = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                high = max(high, grid[i][j]);
                low = min(low , grid[i][j]);
            }
        }

        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSwim(mid, grid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};