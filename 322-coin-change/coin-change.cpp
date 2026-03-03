// class Solution {
// public:
//     int dp[10001][13];

//     int solve(vector<int>& coins, int target, int idx) {
//         if (target == 0) return 0;
//         if (idx == coins.size()) return INT_MAX;
//         if (target < 0) return INT_MAX;

//         if (dp[target][idx] != -1)
//             return dp[target][idx];

//         int not_take = solve(coins, target, idx + 1);

//         int take = INT_MAX;
//         if (coins[idx] <= target) {
//             int res = solve(coins, target - coins[idx], idx);
//             if (res != INT_MAX)
//                 take = 1 + res;
//         }

//         return dp[target][idx] = min(take, not_take);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         memset(dp, -1, sizeof(dp));

//         int ans = solve(coins, amount, 0);

//         return (ans == INT_MAX ? -1 : ans);
//     }
// };

// tabulation bottom up;

class Solution {
public:
     int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int>dp(amount + 1 , INF);
        dp[0] = 0;
        for(int coin : coins){
            for(int j = coin ; j <= amount ; j++){
                dp[j] = min(dp[j] , 1 + dp[j - coin]);
            }
        }
        return (dp[amount] >= INF ? -1 : dp[amount]);
    }
};