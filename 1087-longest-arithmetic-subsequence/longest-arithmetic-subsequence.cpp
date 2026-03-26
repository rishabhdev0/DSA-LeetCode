// class Solution {
// public:
//     int dp[1001][1001]; // dp[idx][diff + 500]  -> to avoid negative value

//     int solve(vector<int>& nums , int idx , int diff){
//         if(dp[idx][diff + 500] != -1) 
//             return dp[idx][diff + 500];

//         int ans = 0;

//         for(int k = idx - 1 ; k >= 0 ; k--){
//             if(nums[idx] - nums[k] == diff){
//                 ans = max(ans , 1 + solve(nums , k , diff));
//             }
//         }

//         return dp[idx][diff + 500] = ans;
//     }

//     int longestArithSeqLength(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));

//         int n = nums.size();
//         int result = 0;

//         for(int i = 0 ; i < n ; i++){
//             for(int j = i + 1 ; j < n ; j++){
//                 int diff = nums[j] - nums[i];
//                 result = max(result , 2 + solve(nums , i , diff));
//             }
//         }

//         return result;
//     }
// };



// bottom - up -> tabulation (just like LIS);


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(1001 , 0));
        int result = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                result = max(result , dp[i][diff]);
            }
        }
        return result;
    }
};

