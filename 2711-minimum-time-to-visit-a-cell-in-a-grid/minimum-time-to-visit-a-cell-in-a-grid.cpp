
class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        if(n == 1 && m == 1) return 0;

        if((n == 1 || grid[1][0] > 1) &&
           (m == 1 || grid[0][1] > 1)) return -1;

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int time = cell.first;
            int i = cell.second.first;
            int j = cell.second.second;

            if(visited[i][j]) continue;

            visited[i][j] = true;

            if(i == n - 1 && j == m - 1) {
                return time;
            }

            for(auto dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_j >= 0 &&
                   new_i < n && new_j < m &&
                   !visited[new_i][new_j]) {

                    if(time >= grid[new_i][new_j] - 1) {
                        pq.push({time + 1, {new_i, new_j}});
                    }
                    else if((grid[new_i][new_j] - time) % 2 == 0) {
                        pq.push({grid[new_i][new_j] + 1, {new_i, new_j}});
                    }
                    else {
                        pq.push({grid[new_i][new_j], {new_i, new_j}});
                    }
                }
            }
        }

        return -1;
    }
};
