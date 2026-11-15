class Solution {
public:
    typedef long long ll;
    int n;
    ll dp[100001];
    unordered_map<int, ll> freq;

    ll solve(vector<int>& nums, int idx) {
        if (idx >= n) return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // skip
        ll skip = solve(nums, idx + 1);

        // take
        int next_idx = lower_bound(
            nums.begin() + idx + 1,
            nums.end(),
            nums[idx] + 3
        ) - nums.begin();

        ll took = 1LL * nums[idx] * freq[nums[idx]];

        if (next_idx < n) {
            took += solve(nums, next_idx);
        }

        return dp[idx] = max(skip, took);
    }

    long long maximumTotalDamage(vector<int>& power) {
        freq.clear();

        for (auto &p : power) {
            freq[p]++;
        }

        vector<int> nums;
        for (auto &it : freq) {
            nums.push_back(it.first);
        }

        sort(nums.begin(), nums.end());

        n = nums.size();   

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0);
    }
};