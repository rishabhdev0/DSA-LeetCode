class Solution {
public:
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    queue<pair<int, int>> que;

                    que.push({i, j});
                    grid[i][j] = '0';

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
                                grid[newRow][newCol] == '1'
                            ) {
                                grid[newRow][newCol] = '0';
                                que.push({newRow, newCol});
                            }
                        }
                    }

                    islands++;
                }
            }
        }

        return islands;
    }
};