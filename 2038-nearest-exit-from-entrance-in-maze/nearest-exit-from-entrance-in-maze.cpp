class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                // Check if current position is an exit (but not the entrance)
                if ((x == 0 || x == row - 1 || y == 0 || y == col - 1) && 
                    !(x == entrance[0] && y == entrance[1])) {
                    return steps;
                }
                
                
                for (auto& dir : direction) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    
                    // Check if new position is valid and not visited
                    if (newX >= 0 && newX < row && newY >= 0 && newY < col && 
                        maze[newX][newY] == '.') {
                        q.push({newX, newY});
                        maze[newX][newY] = '+'; // Mark as visited
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};