class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int negativeCount = 0;

        for(int i = 0; i < n; i++){
            int start = 0;
            int end = grid[i].size() - 1;

            while(start <= end){
                int mid = start + (end - start) / 2;

                if(grid[i][mid] >= 0){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }

            negativeCount += grid[i].size() - start;
        }

        return negativeCount;
    }
};