class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        result[0][0] = 0;  
        
        // Priority queue: {effort, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});  
        
        while(!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            
            int currentEffort = current[0];
            int x = current[1];
            int y = current[2];
            
            // If we reached destination, return effort
            if(x == rows - 1 && y == cols - 1) {
                return currentEffort;
            }
            
            for(auto &dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                // Check if new position is within bounds
                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                    // Calculate absolute difference between current and new cell
                    int abs_diff = abs(heights[x][y] - heights[new_x][new_y]);
                    
                    int new_effort = max(currentEffort, abs_diff);
                
                   
                    if(new_effort < result[new_x][new_y]) {
                        result[new_x][new_y] = new_effort;
                        pq.push({new_effort, new_x, new_y});
                    }
                }
            }
        }
        
        return result[rows-1][cols-1];
    }
};