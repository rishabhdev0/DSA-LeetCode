// class Solution {
// public:
//     int dp[1001][1001];

//     bool isPalindrome(string &s, int i, int j) {
//         if(i >= j) return true;  
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == s[j])
//             return dp[i][j] = isPalindrome(s, i + 1, j - 1);
//         return dp[i][j] = 0; 
//     }

//     int countSubstrings(string s) {
//         int n = s.length();
//         int count = 0;
//         memset(dp, -1, sizeof(dp));
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
//                 if(isPalindrome(s, i, j)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


// now using the blue print or the table filling method 

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n , vector<bool>(n , false));
        int count = 0;
        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i <= n - len ; i++){
                int j = i + len - 1;
                if(len == 1){
                    dp[i][j] = true;
                }else if(len == 2){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] == true){
                    count++;
                }
            }
        }
        return count;
    }
};