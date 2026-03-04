class Solution {
public:
    int dp[21][2001];
    int totalSum;

    int solve(vector<int>& nums, int target, int currSum, int idx) {
        if (idx == nums.size()) {
            return currSum == target;
        }

        if (dp[idx][currSum + totalSum] != -1) {
            return dp[idx][currSum + totalSum];
        }

        int plus = solve(nums, target, currSum + nums[idx], idx + 1);
        int minus = solve(nums, target, currSum - nums[idx], idx + 1);

        return dp[idx][currSum + totalSum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        // if (abs(target) > totalSum) return 0;

        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0, 0);
    }
};