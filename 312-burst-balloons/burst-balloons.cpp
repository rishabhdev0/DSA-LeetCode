class Solution {
public:
    int dp[305][305];

    int solve(vector<int>& nums, int i, int j) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int max_score = 0;

        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1]
                      + solve(nums, i, k - 1)
                      + solve(nums, k + 1, j);

            max_score = max(max_score, coins);
        }

        return dp[i][j] = max_score;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));

        return solve(nums, 1, n);
    }
};