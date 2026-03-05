// class Solution {
// public:
//     int dp[201][201];

//     int solve(vector<vector<int>>& grid, int row, int col, int i, int j) {

//         if(i == row - 1 && j == col - 1)
//             return grid[i][j];

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         if(i == row - 1) {
//             return dp[i][j] = grid[i][j] + solve(grid, row, col, i, j + 1);
//         }

//         if(j == col - 1) {
//             return dp[i][j] = grid[i][j] + solve(grid, row, col, i + 1, j);
//         }

//         return dp[i][j] = grid[i][j] + min(
//             solve(grid, row, col, i + 1, j),
//             solve(grid, row, col, i, j + 1)
//         );
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         memset(dp, -1, sizeof(dp));

//         return solve(grid, n, m, 0, 0);
//     }
// };

// bottom up -> tabulation 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n , vector<int>(m , 0));

        dp[0][0] = grid[0][0];

        for(int i = 1 ; i < n ; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        for(int j = 1 ; j < m ; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }
};