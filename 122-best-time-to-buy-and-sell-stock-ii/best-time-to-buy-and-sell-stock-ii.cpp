// class Solution {
// public:
//      int dp[30001][2]; // 1-> we are buying , 0 -> we just sell it 
//      int solve(vector<int>& prices , int idx , int buy){
//          if(idx == prices.size()) return 0;
//          if(dp[idx][buy] != -1){
//             return dp[idx][buy];
//          }
//          int profit = 0;

//          if(buy == 1){
//             // option 1;
//             int buyStock = -prices[idx] + solve(prices , idx + 1 , 0);
//             int skip = solve(prices , idx + 1 , 1);
//             profit = max(buyStock , skip);
//          }else{
//             // we are selling it;
//             int sellStock = prices[idx] + solve(prices , idx + 1 , 1);
//             int skip = solve(prices , idx + 1, 0);
//             profit = max(sellStock , skip);
//          }
//         return  dp[idx][buy] = profit;
//      }
//     int maxProfit(vector<int>& prices) {
//         memset(dp , -1 , sizeof(dp));
//         return solve(prices , 0 , 1); // we are first choosing but that why its 1;
//     }
// };


// tabulation -> bottom up

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , 0));

        // base case for day 0;
        dp[0][0] = -prices[0]; // can buy foor day 0;
        dp[0][1] = 0; // cant sell on day 0;

        int profit = 0;

        for(int i = 1 ; i < n ; i++){
           int buy = dp[i-1][1] - prices[i];
           int skip = dp[i-1][0];
           dp[i][0] = max(buy , skip);
           // now time for sell;
           int sell = dp[i-1][0] + prices[i];
           int sellSkip = dp[i-1][1];
           dp[i][1] = max(sell , sellSkip);
        }
        return dp[n-1][1];
    }
};