
class Solution {
public:
    int n, m;
    int dp[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {

        if(i >= n || j >= m) return INT_MIN;

        if(i == n - 1 && j == m - 1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            }
            return coins[i][j];
        }

        if(dp[i][j][neu] != -1) {
            return dp[i][j][neu];
        }

        int take = coins[i][j] + max(
            solve(coins, i + 1, j, neu),
            solve(coins, i, j + 1, neu)
        );

        int skip = INT_MIN;

        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i + 1, j, neu - 1);
            int skipRight = solve(coins, i, j + 1, neu - 1);

            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(coins, 0, 0, 2);
    }
};
