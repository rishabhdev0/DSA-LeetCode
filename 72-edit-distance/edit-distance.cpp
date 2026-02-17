class Solution {
public:
    int dp[501][501];

    int solve(string &s1, string &s2, int i, int j) {
        // Base cases
        if (i == s1.length()) return s2.length() - j;
        if (j == s2.length()) return s1.length() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        int insertOp  = 1 + solve(s1, s2, i, j + 1);
        int deleteOp  = 1 + solve(s1, s2, i + 1, j);
        int replaceOp = 1 + solve(s1, s2, i + 1, j + 1);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};