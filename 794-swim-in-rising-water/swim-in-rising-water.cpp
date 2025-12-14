class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int n;

    bool isPossible(int mid, vector<vector<int>>& grid) {
        if (grid[0][0] > mid) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return true;

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !visited[nx][ny] && grid[nx][ny] <= mid) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int l = grid[0][0];
        int r = n * n - 1;
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, grid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
