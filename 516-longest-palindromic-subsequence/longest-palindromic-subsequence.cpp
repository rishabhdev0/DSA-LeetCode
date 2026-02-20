// class Solution {
// public:
//     int dp[1001][1001];

//     int solve(string &s, int i, int j) {
//         if (i > j) return 0;
//         if (i == j) return 1;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == s[j]) {
//             dp[i][j] = 2 + solve(s, i + 1, j - 1);
//         } else {
//             dp[i][j] = max(
//                 solve(s, i + 1, j),
//                 solve(s, i, j - 1)
//             );
//         }
//         return dp[i][j];
//     }

//     int longestPalindromeSubseq(string s) {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, s.length() - 1);
//     }
// };


// bottom up -> more like optimzation

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(int len = 2; len <= n; len++){
            for(int i = 0; i  < n - len + 1 ; i++){
                int j = i + len - 1;

                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};