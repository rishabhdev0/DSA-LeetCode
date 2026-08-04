class Solution {
public:
    int dp[5001][2];

    int solve(int i , int buy , vector<int>& prices){
        if(i >= prices.size()) return 0;

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy){
             int took = -prices[i] + solve(i+1 , 0 , prices);
             int skip = solve(i+1 , 1 , prices);
             profit = max(took , skip);
        }else{
            int sell = prices[i] + solve(i+2 , 1 , prices);
            int skip = solve(i+1 , 0 , prices);
            profit = max(sell , skip);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(0, 1 , prices);
    }
};