// class Solution {
// public:
//     int dp[101];

//     int solve(vector<int>& nums, int idx, int end) {
//         if (idx > end) return 0;
//         if (dp[idx] != -1) return dp[idx];

//         int steal = nums[idx] + solve(nums, idx + 2, end);
//         int skip = solve(nums, idx + 1, end);

//         return dp[idx] = max(steal, skip);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         memset(dp, -1, sizeof(dp));
//         int case1 = solve(nums, 0, n - 2); // took first element , cant took the 2nd last

//         memset(dp, -1, sizeof(dp));
//         int case2 = solve(nums, 1, n - 1); // took the 2nd element and cant took the last ele

//         return max(case1, case2);
//     }
// };


// bottom up appraoch -> tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // CASE 1: houses [0 ... n-2] 
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i <= n - 2; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        int case_1 = dp[n - 2];
        
        // Reset dp
        dp = vector<int>(n, 0);
        
        // CASE 2: houses [1 ... n-1]
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for (int i = 3; i <= n - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        int case_2 = dp[n - 1];
        
        return max(case_1, case_2);
    }
};