class Solution {
public:
    int dp[100001][2][3];

    int solve(vector<int>& prices , int idx , bool buy , int limit){

        if(idx >= prices.size()) return 0;
        if(limit == 0) return 0;

        if(dp[idx][buy][limit] != -1){
            return dp[idx][buy][limit];
        }
        
        int profit = 0;

        if(!buy){
            int took = -prices[idx] + solve(prices , idx + 1 , 1 , limit);
            int not_took = solve(prices , idx + 1 , 0 , limit);
            profit = max(took , not_took);
        }else{
            int took = prices[idx] + solve(prices , idx + 1 , 0 , limit - 1);
            int not_took = solve(prices , idx + 1 , 1 , limit);
            profit = max(took , not_took);
        }

        return dp[idx][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(prices , 0 , 0 , 2);
    }
};