class Solution {
public:
    int dp[21][2001];

    int solve(int idx, int currSum, vector<int>& nums, int target) {
        
        if (idx == nums.size()) {
            return currSum == target;
        }

        int &ans = dp[idx][currSum + 1000];

        if (ans != -1) {
            return ans;
        }

        // Choose +
        int take = solve(idx + 1, currSum + nums[idx], nums, target);

        // Choose -
        int skip = solve(idx + 1, currSum - nums[idx], nums, target);

        return ans = take + skip;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, nums, target);
    }
};