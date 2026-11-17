class Solution {
public:
    int dp[100001];

    int const mod = 1e9 + 7;
    int solve(int low , int high , int zero , int ones , int len){
        if(len > high){
            return 0;
        }
        if(dp[len] != -1){
             return dp[len];
        }

        int count = 0;
        int validCount = 0;
        int append_zero = solve(low , high , zero , ones , len + zero);
        int append_ones = solve(low , high , zero , ones , len + ones);
        if(len >= low && len <= high){
            validCount++;
        }
        count =  (validCount + append_zero + append_ones) % mod;
        return dp[len] = count % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp , -1 , sizeof(dp));
         return solve(low , high , zero , one , 0);
    }
};