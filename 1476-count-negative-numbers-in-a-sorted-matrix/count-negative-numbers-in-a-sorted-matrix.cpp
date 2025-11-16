class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;
            int firstNegativeIndex = m;
            
            while(start <= end) {
                int mid = start + (end - start) / 2;
                if(grid[i][mid] < 0) {
                    firstNegativeIndex = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            
            count += (m - firstNegativeIndex);
        }
        
        return count;
    }
};