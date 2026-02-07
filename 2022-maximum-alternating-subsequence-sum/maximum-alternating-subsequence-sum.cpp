class Solution {
public:
    long long dp[100001][2];

    long long solve(vector<int>& nums, int idx, bool even) {
        if (idx == nums.size()) return 0;

        if (dp[idx][even] != -1)
            return dp[idx][even];

        // option 1: skip current element
        long long skip = solve(nums, idx + 1, even);

        // option 2: take current element
        long long take;
        if (even)
            take = nums[idx] + solve(nums, idx + 1, !even);
        else
            take = -nums[idx] + solve(nums, idx + 1, !even);

        return dp[idx][even] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, true); // start with even
    }
};
