class Solution {
public:
    int dp[1001][2001];

    int solve(vector<vector<int>>& piles, int k, int idx) {
        if (k == 0 || idx == piles.size())
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int not_take = solve(piles, k, idx + 1);

        int sum = 0;
        int maxR = 0;

        for (int j = 0; j < min((int)piles[idx].size(), k); j++) {
            sum += piles[idx][j];

            int money = sum + solve(piles, k - (j + 1), idx + 1);

            maxR = max(maxR, money);
        }

        return dp[idx][k] = max(maxR, not_take);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(piles, k, 0);
    }
};