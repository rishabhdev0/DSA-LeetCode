class Solution {
public:
    int dp[301][5001];

    int solve(vector<int>& coins, int idx, int amount) {
      
        if (amount == 0) return 1;
        if (idx >= coins.size()) return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 0;
        if (coins[idx] <= amount) {
            take = solve(coins, idx, amount - coins[idx]); 
        }

        int not_take = solve(coins, idx + 1, amount);

        return dp[idx][amount] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, 0, amount);
    }
};