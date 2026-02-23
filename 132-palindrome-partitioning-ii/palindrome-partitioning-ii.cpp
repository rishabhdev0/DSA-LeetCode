// class Solution {
// public:
//     bool isPalindrome(string &s , int i , int j){
//        while(i <= j){
//         if(s[i] != s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//        return true;
//     }
//     int dp[2001][2001];
//     int solve(string &s , int i , int j){
//         if(i >= j) return 0;
//         if(isPalindrome(s , i , j)) return 0;
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int result = INT_MAX;
//         // trying the every cut 
//         for(int k = i ; k < j ; k++){
//             if(isPalindrome(s, i  , k)){
//                 int temp = 1 + solve(s , k + 1 , j);
//                 result = min(result , temp);
//             }
//         }
//         return dp[i][j] = result;
//     }
//     int minCut(string s) {
//         memset(dp , -1 , sizeof(dp));
//         return solve(s , 0  , s.length() - 1);
//     }
// };


// tabulation (bottom up);

class Solution {
public:
    bool isPalindrome(string &s , int i , int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.length();

        // palindrome dp
        vector<vector<bool>> dp(n , vector<bool>(n , false));

        for(int i = 0 ; i < n ; i++){
            dp[i][i] = true;
        }

        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;

                if(s[i] == s[j]){
                    if(len == 2){
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }

        // result[i] = min cuts for s[0..i]
        vector<int> result(n , INT_MAX);

        for(int i = 0 ; i < n ; i++){
            if(dp[0][i]){
                result[i] = 0;
            } else {
                for(int k = 0 ; k < i ; k++){
                    if(dp[k+1][i] && result[k] != INT_MAX){
                        result[i] = min(result[i] , result[k] + 1);
                    }
                }
            }
        }

        return result[n-1];
    }
};