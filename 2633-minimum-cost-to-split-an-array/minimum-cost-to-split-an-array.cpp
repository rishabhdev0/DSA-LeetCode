
class Solution {
public:
    int n;
    int dp[1001];

    int solve(vector<int>& nums, int k,
              vector<vector<int>>& trimmed, int idx) {
        if (idx == n) return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int min_result = INT_MAX;

        for (int i = idx; i < n; i++) {
            int result = k + trimmed[idx][i]
                         + solve(nums, k, trimmed, i + 1);

            min_result = min(min_result, result);
        }

        return dp[idx] = min_result;
    }

    int minCost(vector<int>& nums, int k) {
        n = nums.size();

        vector<vector<int>> trimmed(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int len = 0;

            for (int j = i; j < n; j++) {
                freq[nums[j]]++;

                if (freq[nums[j]] == 2)
                    len += 2;
                else if (freq[nums[j]] > 2)
                    len++;

                trimmed[i][j] = len;
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(nums, k, trimmed, 0);
    }
};
