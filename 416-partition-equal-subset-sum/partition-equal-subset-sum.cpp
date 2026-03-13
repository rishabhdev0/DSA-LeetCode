class Solution {
public:
     int dp[201][20001];

     bool solve(vector<int>& nums , int target , int curr , int idx){
        if(curr == target) return true;
        if(idx >= nums.size() || curr > target) return false;

        if(dp[idx][curr] != -1){
            return dp[idx][curr];
        }

      bool take = solve(nums , target  , curr + nums[idx] , idx + 1);
      bool skip = solve(nums , target , curr , idx +1);

      return dp[idx][curr] = take || skip;

     }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        if(total % 2 != 0) return false;
        memset(dp , -1 , sizeof(dp));
        return solve(nums , total / 2 , 0 , 0);
    }
};