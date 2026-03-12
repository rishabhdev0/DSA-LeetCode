// class Solution {
// public:
//     int dp[31][1001];
//     const int MOD = 1e9 + 7;

//     int solve(int dice , int k , int target){
//         if(dice == 0 && target == 0) return 1;
//         if(dice == 0 || target < 0) return 0;

//         if(dp[dice][target] != -1){
//             return dp[dice][target];
//         }

//         long long way = 0;

//         for(int i = 1 ; i <= k ; i++){
//             way = (way + solve(dice-1 , k , target - i))%MOD;
//         }
//         return dp[dice][target] = way;
//     }
//     int numRollsToTarget(int n, int k, int target) {
//         memset(dp , -1 , sizeof(dp));
//          return solve(n , k , target);
//     }
// };


// bottom up -> tabulation 

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
         vector<vector<int>>dp(n+1 , vector<int>(target +1  , 0));
         const int MOD = 1e9+7;
    
         dp[0][0] = 1;

         for(int i = 1 ; i <= n  ; i++){
            for(int j = 1 ; j <= target ; j++){
                int way = 0;
                for(int face = 1 ; face <= k ; face++){
                    if(j - face >= 0){
                        way = (way + dp[i-1][j - face]) % MOD;
                    }
                }
                dp[i][j] = way;
            }
         } 
         return dp[n][target];
    }
};