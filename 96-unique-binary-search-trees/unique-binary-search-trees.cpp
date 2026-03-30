class Solution {
public:
    int dp[20];

    int dfs(int n) {
        if (n <= 1) return 1;  

        if (dp[n] != -1) return dp[n];

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int left = dfs(i - 1);
            int right = dfs(n - i);
            ans += left * right;
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return dfs(n);
    }
};