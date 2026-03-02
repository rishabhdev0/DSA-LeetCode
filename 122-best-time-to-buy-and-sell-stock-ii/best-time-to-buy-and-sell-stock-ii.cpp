class Solution {
public:
     int dp[30001][2]; // 1-> we are buying , 0 -> we just sell it 
     int solve(vector<int>& prices , int idx , int buy){
         if(idx == prices.size()) return 0;
         if(dp[idx][buy] != -1){
            return dp[idx][buy];
         }
         int profit = 0;

         if(buy == 1){
            // option 1;
            int buyStock = -prices[idx] + solve(prices , idx + 1 , 0);
            int skip = solve(prices , idx + 1 , 1);
            profit = max(buyStock , skip);
         }else{
            // we are selling it;
            int sellStock = prices[idx] + solve(prices , idx + 1 , 1);
            int skip = solve(prices , idx + 1, 0);
            profit = max(sellStock , skip);
         }
        return  dp[idx][buy] = profit;
     }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(prices , 0 , 1); // we are first choosing but that why its 1;
    }
};