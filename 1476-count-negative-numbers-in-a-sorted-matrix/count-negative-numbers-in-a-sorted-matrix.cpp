class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            int s = 0;
            int e = grid[i].size() - 1; 
            while (s <= e) {
                int mid = s + (e - s) / 2;
                
                if (grid[i][mid] < 0) { 
                    e = mid - 1;  
                } else {
                    s = mid + 1;  
                }
            }
          
            count += (grid[i].size() - s); 
        }
        
        return count;
    }
};
