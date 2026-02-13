// class Solution {
// public:
//     int dp[1001][1001];

//     int solve(string &text1 , string &text2 , int i , int j){
        
//         if(i == text1.length() || j == text2.length())
//             return 0;

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         if(text1[i] == text2[j]){
//             return dp[i][j] = 1 + solve(text1 , text2 , i+1 , j+1);
//         }

//      return dp[i][j] = max( solve(text1 , text2 , i+1 , j), solve(text1 , text2 , i , j +1));
    
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(dp , -1 , sizeof(dp));
//         return solve(text1 , text2 , 0 , 0);
//     }
// };


// tabulation method;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};