class Solution {
private:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j) { 
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) 
            return 0;
        grid[i][j] = 0;
        int area = 1;
        for(auto dir : direction) {
            int new_i = i + dir[0];  
            int new_j = j + dir[1];  
            area += dfs(grid, new_i, new_j);  
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_Area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(grid, i, j);  
                    max_Area = max(max_Area, area);
                }
            }
        }
        return max_Area;
    }
};