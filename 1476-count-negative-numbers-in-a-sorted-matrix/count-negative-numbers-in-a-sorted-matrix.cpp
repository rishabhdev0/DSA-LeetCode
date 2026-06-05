class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int count_negative = 0;
        for(int i = 0 ; i < n ; i++){
            int start = 0;
            int end = grid[i].size() - 1;
            int first_negative = grid[i].size();

            while(start <= end){
                int mid = start + (end - start) / 2;
                if(grid[i][mid] < 0){
                    first_negative = mid;
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
            count_negative += (grid[i].size() - first_negative);
        }
        return count_negative;
    }
};