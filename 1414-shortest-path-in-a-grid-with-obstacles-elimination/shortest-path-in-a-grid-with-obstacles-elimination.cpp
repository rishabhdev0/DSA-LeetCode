class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 3D visited array: visited[x][y][remaining_k]
        vector<vector<vector<bool>>> visited(n, 
            vector<vector<bool>>(m, 
            vector<bool>(k+1, false)));
        
        queue<vector<int>> q; // [x, y, remaining_k]
        q.push({0, 0, k});
        visited[0][0][k] = true;
        
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                
                int x = current[0];
                int y = current[1];
                int remaining_k = current[2];
                
                if (x == n-1 && y == m-1) {
                    return steps;
                }
                
                for(auto& dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                        // If it's an obstacle
                        if(grid[new_x][new_y] == 1) {
                            if(remaining_k > 0 && !visited[new_x][new_y][remaining_k-1]) {
                                visited[new_x][new_y][remaining_k-1] = true;
                                q.push({new_x, new_y, remaining_k-1});
                            }
                        }

                        else {
                            if(!visited[new_x][new_y][remaining_k]) {
                                visited[new_x][new_y][remaining_k] = true;
                                q.push({new_x, new_y, remaining_k});
                            }
                        }
                    }
                }
            }
            steps++; 
        }
        
        return -1;
    }
};