class Solution {
public:
    int dp[501][501];

    int solve(string& s, int start, int last) {

        if (start >= last) {
            return 0;
        }

        if (dp[start][last] != -1) {
            return dp[start][last];
        }

        if (s[start] == s[last]) {
            return dp[start][last] =
                solve(s, start + 1, last - 1);
        }

        int count = 1 + min(
            solve(s, start + 1, last),
            solve(s, start, last - 1)
        );

        return dp[start][last] = count;
    }

    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, s.length() - 1);
    }
};