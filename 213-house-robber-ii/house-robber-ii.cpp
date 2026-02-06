class Solution {
public:
    int dp[101];

    int solve(vector<int>& nums, int idx, int end) {
        if (idx > end) return 0;
        if (dp[idx] != -1) return dp[idx];

        int steal = nums[idx] + solve(nums, idx + 2, end);
        int skip = solve(nums, idx + 1, end);

        return dp[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        memset(dp, -1, sizeof(dp));
        int case1 = solve(nums, 0, n - 2); // took first element , cant took the 2nd last

        memset(dp, -1, sizeof(dp));
        int case2 = solve(nums, 1, n - 1); // took the 2nd element and cant took the last ele

        return max(case1, case2);
    }
};
