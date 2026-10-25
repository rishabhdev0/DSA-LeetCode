class Solution {
public:
    const int mod = 1e9 + 7;
    int n;
    int dp[1001][1001];

    int solve(vector<int>& nums, int idx, int sum, int k) {
        if (idx == n) return 1;

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        int not_take = solve(nums, idx + 1, sum, k);

        int take = 0;
        if (sum + nums[idx] < k) {
            take = solve(nums, idx + 1, sum + nums[idx], k);
        }

        return dp[idx][sum] = (not_take + 1LL * take) % mod;
    }

    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        if (total < 2LL * k) return 0;

        memset(dp, -1, sizeof(dp));

        long long bad = solve(nums, 0, 0, k);

        long long totalWays = 1;
        for (int i = 0; i < n; i++) {
            totalWays = (totalWays * 2) % mod;
        }

        return (totalWays - 2 * bad % mod + mod) % mod;
    }
};