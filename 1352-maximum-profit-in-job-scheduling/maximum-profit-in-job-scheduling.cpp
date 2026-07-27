class Solution {
public:
    int dp[50001];

    int solve(vector<vector<int>>&nums  , int idx){
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }
        int next = lower_bound(nums.begin() , nums.end() , vector<int>{nums[idx][1] , 0 , 0}) - 
        nums.begin();
       
       int take = nums[idx][2] + solve(nums ,next);
       int not_took = solve(nums , idx + 1);
       
       return dp[idx] = max(take , not_took);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>nums(n , vector<int>(3));
        for(int i = 0 ; i < n ; i++){
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }
        sort(nums.begin() , nums.end());
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};