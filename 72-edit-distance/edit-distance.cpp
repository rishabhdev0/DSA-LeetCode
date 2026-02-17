// class Solution {
// public:
//     int dp[501][501];

//     int solve(string &s1, string &s2, int i, int j) {
//         // Base cases
//         if (i == s1.length()) return s2.length() - j;
//         if (j == s2.length()) return s1.length() - i;

//         if (dp[i][j] != -1) return dp[i][j];

//         if (s1[i] == s2[j]) {
//             return dp[i][j] = solve(s1, s2, i + 1, j + 1);
//         }

//         int insertOp  = 1 + solve(s1, s2, i, j + 1);
//         int deleteOp  = 1 + solve(s1, s2, i + 1, j);
//         int replaceOp = 1 + solve(s1, s2, i + 1, j + 1);

//         return dp[i][j] = min({insertOp, deleteOp, replaceOp});
//     }

//     int minDistance(string word1, string word2) {
//         memset(dp, -1, sizeof(dp));
//         return solve(word1, word2, 0, 0);
//     }
// };


// bottom - up -> tabualation

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;   
        }
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;   
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int insert  = dp[i][j + 1];
                    int del     = dp[i + 1][j];
                    int replace = dp[i + 1][j + 1];

                    dp[i][j] = 1 + min({insert, del, replace});
                }
            }
        }

        return dp[0][0];
    }
};