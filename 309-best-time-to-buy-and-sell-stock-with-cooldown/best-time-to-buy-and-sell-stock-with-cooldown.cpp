// class Solution {
// public:
//     int dp[5001][2];

//     int solve(vector<int>& prices, int idx, bool purchase) {
//         if (idx >= prices.size()) return 0;

//         if (dp[idx][purchase] != -1)
//             return dp[idx][purchase];

//         int profit = 0;

//         if (purchase) {
//             int buy = -prices[idx] + solve(prices, idx + 1, false);
//             int not_buy = solve(prices, idx + 1, true);
//             profit = max(buy, not_buy);
//         } else {
//             // sell with cooldown
//             int sell = prices[idx] + solve(prices, idx + 2, true);
//             int not_sell = solve(prices, idx + 1, false);
//             profit = max(sell, not_sell);
//         }

//         return dp[idx][purchase] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         memset(dp, -1, sizeof(dp));
//         return solve(prices, 0, true);
//     }
// };


// bottom up-> tabulation 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2 , vector<int>(2, 0));
         for(int i = n-1 ; i >= 0 ; i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+2][1] , dp[i+1][0]);
         }
         return dp[0][1];
    }
};