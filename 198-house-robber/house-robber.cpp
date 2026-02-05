class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums , int idx){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1)
         return dp[idx];

        int steal = nums[idx] + solve(nums , idx + 2);
        int skip = solve(nums, idx + 1);

        dp[idx] = max(steal, skip);

        return dp[idx];
    }
    int rob(vector<int>& nums) {
       memset(dp , -1 , sizeof(dp));
       return solve(nums  , 0); 
    }
};