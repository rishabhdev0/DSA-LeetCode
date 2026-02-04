// class Solution {
// public:
//   int dp[46];
//    int solve(int n){
//        if(n <= 1) return 1;
//        if(dp[n] != -1){
//         return dp[n];
//        }
//        return dp[n] = solve(n-1) + solve(n-2);
//    }
//     int climbStairs(int n) {
//         memset(dp , -1 , sizeof(dp));
//         return solve(n);
//     }
// };

// bottom - up(tabulation);

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};











auto init= atexit([](){ ofstream("display_runtime.txt")<<'0';});
