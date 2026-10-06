class Solution {

public:

    int dp[51][6];

    int solve(int n, int start) {

        if(n == 0) return 1;

        if(dp[n][start] != -1) {
            return dp[n][start];
        }

        int ans = 0;

        for(int i = start; i < 5; i++) {
            ans += solve(n - 1, i);
        }

        return dp[n][start] = ans;
    }

    int countVowelStrings(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(n, 0);
    }
};