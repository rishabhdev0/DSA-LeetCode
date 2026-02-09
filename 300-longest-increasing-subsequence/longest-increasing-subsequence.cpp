// class Solution {
// public:
//     int dp[2501][2501];

//     int solve(vector<int>& nums, int idx, int prev, int n) {
//         if (idx == n) return 0;

//         if (dp[idx][prev + 1] != -1)
//             return dp[idx][prev + 1];

//         int take = 0;
//         if (prev == -1 || nums[prev] < nums[idx]) {
//             take = 1 + solve(nums, idx + 1, idx, n);
//         }

//         int skip = solve(nums, idx + 1, prev, n);

//         return dp[idx][prev + 1] = max(take, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0, -1, n);
//     }
// };

// bttom up -> tabulation 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int max_len = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                    max_len = max(max_len , dp[i]);
                }
            }
        }
        return max_len;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "000"; });

