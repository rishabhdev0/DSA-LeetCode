// class Solution {
// public:
//     int solve(string &word1 , string &word2 , int i , int j , vector<vector<int>> &dp){
//          if(i == word1.length()) return word2.length() - j;
//          if(j == word2.length()) return word1.length() - i;
//          if(dp[i][j] != -1){
//             return dp[i][j];
//          }
//          if(word1[i] == word2[j]){
//             return dp[i][j] = solve(word1 , word2 , i + 1 , j + 1 , dp);
//          }
//          // delete operation;
//          int del_1 =  solve(word1 , word2 , i + 1 , j , dp);
//          int del_2 = solve(word1 , word2 , i , j + 1 , dp);

//          return dp[i][j] = 1 + min(del_1 , del_2);
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>>dp(n , vector<int>(m, -1));
//         return solve(word1 , word2 , 0 , 0  , dp);
//     }
// };


// tabulation 



class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] = LCS of first i chars of word1 and first j chars of word2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs = dp[n][m];
        return n + m - 2 * lcs;
    }
}; 