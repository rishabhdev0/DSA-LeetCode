class Solution {
public:
    int dp[1001][1002];

    int solve(vector<int>& nums, int i, int diff) {
        if (i < 0)
            return 0;

        if (dp[i][diff + 501] != -1) {
            return dp[i][diff + 501];
        }

        int temp = 0;

        for (int k = i - 1; k >= 0; k--) {
            if (nums[i] - nums[k] == diff) {
                temp = max(temp, 1 + solve(nums, k, diff));
            }
        }

        return dp[i][diff + 501] = temp;
    }

    int longestArithSeqLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                result = max(result, 2 + solve(nums, i, diff));
            }
        }

        return result;
    }
};