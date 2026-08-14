class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (auto num : nums) {
            freq[num]++;
        }

        vector<int> unique;

        for (auto& it : freq) {
            unique.push_back(it.first);
        }

        sort(unique.begin(), unique.end());

        int n = unique.size();

        vector<int> dp(n, 0);

        dp[0] = unique[0] * freq[unique[0]];

        for (int i = 1; i < n; i++) {
            long long val = 1LL * unique[i] * freq[unique[i]];

            if (unique[i] == unique[i - 1] + 1) {
                int took = val + (i > 1 ? dp[i - 2] : 0);
                int skip = dp[i - 1];

                dp[i] = max(took, skip);
            }
            else {
                dp[i] = val + dp[i - 1];
            }
        }

        return dp[n - 1];
    }
};