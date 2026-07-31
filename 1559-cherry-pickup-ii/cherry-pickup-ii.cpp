class Solution {
public:
    int dp[71][71][71];
    int n;
    int m;
    int solve(vector<vector<int>> &grid , int row , int col1 , int col2){
        if(row >= n){
            return 0;
        }


        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

       int cherry = grid[row][col1];

        if(col1 != col2){
            cherry += grid[row][col2];
        }

        int best = 0;

        for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                int newc1 = col1 + i;
                int newc2 = col2 + j;
                int new_row = row + 1;
                if(newc1 >= 0 && newc1 < m && newc2 >= 0 && newc2 < m){
                    best = max(best , solve(grid , new_row , newc1 , newc2));
                }
            }
        }
        return dp[row][col1][col2] = best + cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
         memset(dp , -1 , sizeof(dp));
         return solve(grid , 0 , 0 , m - 1);
    }
};