// class Solution {
// public:
//     int dp[50001][2];

//     int solve(vector<int>& prices, int fee, int idx, bool purchase) {
//         if (idx >= prices.size()) return 0;

//         if (dp[idx][purchase] != -1) {
//             return dp[idx][purchase];
//         }

//         int profit = 0;

//         if (purchase) {
//             int took = -prices[idx] + solve(prices, fee, idx + 1, false);
//             int not_took = solve(prices, fee, idx + 1, true);
//             profit = max(took, not_took);
//         } else {
//             int sell = prices[idx] - fee + solve(prices, fee, idx + 1, true);
//             int not_sell = solve(prices, fee, idx + 1, false);
//             profit = max(sell, not_sell);
//         }

//         return dp[idx][purchase] = profit;
//     }

//     int maxProfit(vector<int>& prices, int fee) {
//         memset(dp, -1, sizeof(dp));
//         return solve(prices, fee, 0, true);
//     }
// };

// bottom up -----> tabulation 

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
         vector<vector<int>>dp(n+2 , vector<int>(2 , 0));
         for(int i = n - 1 ; i >= 0 ; i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
            dp[i][0] =  max(prices[i] + dp[i+1][1] - fee , dp[i+1][0]);
         }
         return dp[0][1];
    }
};