class Solution {
public:
    int n;

    int find(int idx, vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin() + idx, nums.end(), target) - nums.begin();

        if (lb < n && nums[lb] == target) return lb;

        return -1;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(2, 1));

        int result = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int inc = 0; inc <= 1; inc++) {

                int curr = nums[i] + inc;

                // Option 1: Find curr + 1
                int j = find(i + 1, nums, curr + 1);

                if (j != -1) {
                    dp[i][inc] = max(dp[i][inc], 1 + dp[j][0]);
                }

                // Option 2: Find curr
                j = find(i + 1, nums, curr);

                if (j != -1) {
                    dp[i][inc] = max(dp[i][inc], 1 + dp[j][1]);
                }

                result = max(result, dp[i][inc]);
            }
        }

        return result;
    }
};
