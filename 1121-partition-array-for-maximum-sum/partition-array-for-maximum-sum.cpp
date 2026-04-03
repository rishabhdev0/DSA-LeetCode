class Solution {
public:
    int dp[501];

    int solve(vector<int>& arr, int k, int i) {
        if (i >= arr.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int max_till_now = INT_MIN;
        int result = 0;

        for (int j = i; j < arr.size() && j < i + k; j++) {
            max_till_now = max(max_till_now, arr[j]);

            int len = j - i + 1;
            int answer = len * max_till_now + solve(arr, k, j + 1);

            result = max(result, answer);
        }

        return dp[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, k, 0);
    }
};