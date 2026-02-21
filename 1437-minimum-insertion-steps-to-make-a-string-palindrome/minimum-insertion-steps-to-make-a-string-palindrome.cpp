// class Solution {
// public:
//     int dp[501][501];

//     int solve(string &s, int i, int j) {
//         if (i >= j) return 0;   

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == s[j]) {
//             dp[i][j] = solve(s, i + 1, j - 1);
//         } else {
//             dp[i][j] = 1 + min(solve(s , i + 1 , j) , solve(s , i , j - 1));
//         }

//         return dp[i][j];
//     }

//     int minInsertions(string s) {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, s.length() - 1);
//     }
// };


// bottom up -> tabulation

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len  + 1 ; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};