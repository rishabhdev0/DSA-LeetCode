class Solution {
public:
    int dp[51][51][51];
    const int INF = 1e9;

    int solve(int r1 , int c1 , int r2 , vector<vector<int>> &grid){

        int n = grid.size();

        int c2 = r1 + c1 - r2;
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n){
            return -INF;
        }
        if(grid[r1][c1] == - 1 || grid[r2][c2] == -1){
            return - INF;
        }

        if(r1 == n - 1&& c1 == n -1){
            return grid[n-1][n-1];
        }

        if(dp[r1][c1][r2] != -1){
            return dp[r1][c1][r2];
        }

        int cherry;
        if(r1 == r2 && c1 == c2){
            cherry = grid[r1][c1];
        }else{
            cherry = grid[r1][c1] + grid[r2][c2];
        }
        int best = -INF;

        best = max({solve(r1 + 1 , c1 , r2 + 1 , grid) , solve(r1 + 1, c1 , r2 , grid) ,
        solve(r1 , c1 + 1, r2 + 1 , grid) , solve(r1 , c1 + 1 , r2 , grid)});

        if(best == -INF){
            return dp[r1][c1][r2] = -INF;
        }
        return dp[r1][c1][r2] = best + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        return max(0 , solve(0 , 0 , 0 , grid));
    }
};