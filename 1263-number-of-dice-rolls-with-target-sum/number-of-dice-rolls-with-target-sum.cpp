class Solution {
public:
     int dp[31][1001];
    int const mod = 1e9 + 7;
     int solve(int n , int k , int target , int sum){
        if(n == 0 && sum == target){
            return 1;
        }

        if(n ==0 && sum != target){
            return 0;
        }

        if(n == 0){
            return 0;
        }

        if(dp[n][sum] != -1){
            return dp[n][sum];
        }

        long long way = 0;

        for(int i = 1 ; i <= k ; i++){
            way = (way + solve(n-1 , k  , target , sum + i)) % mod;
        }

        return dp[n][sum] = way;

     }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp , -1 , sizeof(dp));
        return solve(n , k , target , 0);   
    }
};