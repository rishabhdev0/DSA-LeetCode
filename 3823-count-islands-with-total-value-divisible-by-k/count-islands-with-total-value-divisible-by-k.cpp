class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    long long dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
            return 0LL;
        }

        long long sum = grid[i][j];
        grid[i][j] = 0;

        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            sum += dfs(grid, new_i, new_j);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};