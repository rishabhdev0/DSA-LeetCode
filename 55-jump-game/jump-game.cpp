class Solution {
public:
    int dp[10001];

    bool solve(vector<int>& nums , int idx){

        if(idx >= nums.size()-1) 
            return true;

        if(dp[idx] != -1) 
            return dp[idx];

        int maxJump = nums[idx];

        for(int jump = 1 ; jump <= maxJump ; jump++){

            if(solve(nums , idx + jump))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {

        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};