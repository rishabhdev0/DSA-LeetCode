class Solution {
public:
    int dp[10001];
    int n;

    int solve(vector<int>& nums, int idx) {
        if (idx >= n - 1) return 0;

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 1e9;

        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n) {
                ans = min(ans, 1 + solve(nums, idx + i));
            }
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0);
    }
};