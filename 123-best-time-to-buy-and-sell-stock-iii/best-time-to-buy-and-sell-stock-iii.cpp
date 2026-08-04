class Solution {
public:
    int dp[100001][2][2];

    int solve(int i, int buy, int total , vector<int>& prices) {
        if (i >= prices.size() || total == 2)
            return 0;

        if (dp[i][buy][total] != -1)
            return dp[i][buy][total];

        int profit = 0;

        if (buy) {
            int took = -prices[i] + solve(i + 1, 0,total, prices);
            int skip = solve(i + 1, 1,total , prices);
            profit = max(took, skip);
        } else {
            int sell = prices[i] + solve(i + 1,1 , total + 1 , prices);
            int skip = solve(i + 1, 0, total ,prices);
            profit = max(sell, skip);
        }

        return dp[i][buy][total] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0 ,prices);
    }
};