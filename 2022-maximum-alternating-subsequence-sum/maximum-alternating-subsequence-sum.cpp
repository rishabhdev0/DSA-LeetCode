class Solution {
public:
    long long dp[100001][2];
    int n;

    long long solve(vector<int>& nums, int idx, int sign) {
        if (idx >= n)
            return 0;

        if (dp[idx][sign] != -1)
            return dp[idx][sign];

        // Skip nums[idx]
        long long notTake = solve(nums, idx + 1, sign);

        // Take nums[idx]
        long long take;

        if (sign == 0) {
            // + nums[idx]
            take = nums[idx] + solve(nums, idx + 1, 1);
        }
        else {
            // - nums[idx]
            take = -nums[idx] + solve(nums, idx + 1, 0);
        }

        return dp[idx][sign] = max(take, notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, 0);
    }
};