// class Solution {
// public:
//     int dp[1001][1001];

//     int solve(string& s1, string& s2, int i, int j){
//         if(i >= s1.length() || j >= s2.length()) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         // match
//         if(s1[i] == s2[j]){
//             return dp[i][j] = (int)s1[i] + solve(s1, s2, i+1, j+1);
//         }

//         // not match
//         return dp[i][j] = max(
//             solve(s1, s2, i+1, j),
//             solve(s1, s2, i, j+1)
//         );
//     }

//     int minimumDeleteSum(string s1, string s2) {
//         memset(dp, -1, sizeof(dp));

//         int total = 0;
//         for(char c : s1) total += c;
//         for(char c : s2) total += c;

//         int common = solve(s1, s2, 0, 0);

//         return total - 2 * common;
//     }
// };


// bottom up -> tabulation 



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = (int)s1[i-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int common = dp[n][m];

        int total = 0;
        for(char ch : s1) total += ch;
        for(char ch : s2) total += ch;

        return total - 2 * common;
    }
};