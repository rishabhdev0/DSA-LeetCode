// class Solution {
// public:
//     int dp[21][2001];
//     int totalSum;

//     int solve(vector<int>& nums, int target, int currSum, int idx) {
//         if (idx == nums.size()) {
//            if (currSum == target) return 1;
//             else return 0;
//         }

//         if (dp[idx][currSum + totalSum] != -1) {
//             return dp[idx][currSum + totalSum];
//         }

//         int plus = solve(nums, target, currSum + nums[idx], idx + 1);
//         int minus = solve(nums, target, currSum - nums[idx], idx + 1);

//         return dp[idx][currSum + totalSum] = plus + minus;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         totalSum = accumulate(nums.begin(), nums.end(), 0);

//         // if (abs(target) > totalSum) return 0;

//         memset(dp, -1, sizeof(dp));
//         return solve(nums, target, 0, 0);
//     }
// };

// tabulation -> bottom up approach

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        
        for(int num : nums) {
            totalSum += num;
        }

        // Edge cases
        if(abs(target) > totalSum) return 0;
        if((target + totalSum) % 2 != 0) return 0;

        int subsetSum = (target + totalSum) / 2;

        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for(int num : nums) {
            for(int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};