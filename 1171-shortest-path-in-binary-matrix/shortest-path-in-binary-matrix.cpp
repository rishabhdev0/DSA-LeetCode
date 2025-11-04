class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // i know bfs is optimal but  dijkastra i want to praatice
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // All 8 directions for a binary matrix
        vector<vector<int>> directions = {
            {0, 1},   // right
            {0, -1},  // left  
            {1, 0},   // down
            {-1, 0},  // up
            {1, 1},   // down-right
            {1, -1},  // down-left
            {-1, 1},  // up-right
            {-1, -1}  // up-left
        };
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;  
        // Priority queue: {distance, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({1, 0, 0});  // Start with distance 1 at (0,0)
        
        while(!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            
            int currentDist = current[0];
            int x = current[1];
            int y = current[2];
            
            // If we reached destination, return distance
            if(x == n-1 && y == n-1) {
                return currentDist;
            }
            
            // Explore all 8 directions
            for(auto &dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                // Check if new position is valid
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0) {
                    int newDist = currentDist + 1;
                    
                    // If we found a shorter path, update
                    if(newDist < dist[new_x][new_y]) {
                        dist[new_x][new_y] = newDist;
                        pq.push({newDist, new_x, new_y});
                    }
                }
            }
        }
        
        return -1;  // No path found
    }
};