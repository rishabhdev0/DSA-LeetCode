// class Solution {
// public:
//     vector<int> dp = vector<int>(100005, -1);

//     int fib(int n) {
//         // top-down approach(memoziation)
//         if (n <= 1) return n;

//         if (dp[n] != -1)
//             return dp[n];

//         return dp[n] = fib(n - 1) + fib(n - 2);
//     }
// };

class Solution {
public:
    int fib(int n) {
        // bottom - up approach(tabulation)
        if (n <= 1) return n;
        int dp[10000];
       dp[0] = 0;
       dp[1] = 1;
       for(int i = 2 ; i <= n ; i++){
           dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
    }
};
