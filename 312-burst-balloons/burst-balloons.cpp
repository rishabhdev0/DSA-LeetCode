// class Solution {
// public:
//     int dp[305][305];

//     int solve(vector<int>& nums, int i, int j) {
//         if (i > j) return 0;

//         if (dp[i][j] != -1) return dp[i][j];

//         int max_score = 0;

//         for (int k = i; k <= j; k++) {
//             int coins = nums[i - 1] * nums[k] * nums[j + 1]
//                       + solve(nums, i, k - 1)
//                       + solve(nums, k + 1, j);

//             max_score = max(max_score, coins);
//         }

//         return dp[i][j] = max_score;
//     }

//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();

//         // Add 1 at both ends
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);

//         memset(dp, -1, sizeof(dp));

//         return solve(nums, 1, n);
//     }
// };


// bottom up -> tabulation 

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // i from back → front
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) { // and j from front -> back

               for (int k = i; k <= j; k++) { // checking the every position which ballon on last will give the best result;
                    int coins = nums[i - 1] * nums[k] * nums[j + 1]
                              + dp[i][k - 1]
                              + dp[k + 1][j];

                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }

        return dp[1][n];
    }
};