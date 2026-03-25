class Solution {
public:
    int dp[2][101][1001];

    int solve(vector<int>& prices , bool buy , int k , int idx){
        if(idx >= prices.size()) return 0;
        if(k == 0) return 0;

        if(dp[buy][k][idx] != -1){
            return dp[buy][k][idx];
        }

        int profit = 0;

        if(!buy){
            int took = -prices[idx] + solve(prices , 1 , k , idx + 1);
            int not_took = solve(prices , 0 , k , idx + 1);
            profit = max(took , not_took);
        }else{
            int sell = prices[idx] + solve(prices , 0  , k-1 , idx + 1);
            int not_sell = solve(prices , 1 , k , idx + 1);
            profit = max(sell , not_sell);
        }

        return dp[buy][k][idx] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(prices , 0  , k , 0);
    }
};