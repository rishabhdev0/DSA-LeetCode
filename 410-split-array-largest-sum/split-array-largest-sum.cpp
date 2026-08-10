class Solution {
public:
    int dp[1001][51];

    int solve(vector<int>& nums , int idx , int k){
          if(k == 1){
            int sum  = 0;
            for(int i = idx ; i < nums.size() ; i++){
                sum += nums[i];
            }
            return sum;
          }
          if(dp[idx][k] != -1){
            return dp[idx][k];
          }
          int ans =  INT_MAX;
          int currSum  = 0;
          
          for(int i = idx ; i < nums.size() ; i++){
            currSum += nums[i];
             if (nums.size() - i < k - 1)
                break;
            int remaining = solve(nums , i + 1 , k - 1);

            int largest =  max(currSum , remaining);
            
            ans = min(ans , largest);
          }
          return dp[idx][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0 , k);
    }
};