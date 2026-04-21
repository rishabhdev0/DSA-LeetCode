// class Solution {
// public:
//     int dp[101];

//     int solve(string& s, int idx) {
//         int n = s.length();

//         // Base case
//         if (idx == n) return 1;

//         // Invalid case
//         if (s[idx] == '0') return 0;

//         if (dp[idx] != -1) return dp[idx];

//         // Take single digit
//         int ways = solve(s, idx + 1);

//         // Take two digits
//         if (idx + 1 < n) {
//             if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')) {
//                 ways += solve(s, idx + 2);
//             }
//         }

//         return dp[idx] = ways;
//     }

//     int numDecodings(string s) {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0);
//     }
// };


// tabulation 

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 1; // base case

        for (int i = n - 1; i >= 0; i--) {

            // If current is '0' → no ways
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            // Take single digit
            dp[i] = dp[i + 1];

            // Take two digits
            if (i + 1 < n) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};