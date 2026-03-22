class Solution {
public:
bool solve(vector<int>& nums , vector<bool>& used , int k , int start , int sum , int target){
      if(k == 0) return true;

      if(sum == target){
        return solve(nums , used , k - 1 , 0 , 0 , target);
      }

      for(int i = start ; i < nums.size() ; i++){
        if(!used[i] && sum + nums[i] <= target){
            used[i] = true;
            if(solve(nums , used , k , i + 1 , sum + nums[i] , target)){
                return true;
            }
            used[i] = false;
        }
      }
      return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum % k != 0) return false;
        int target = sum / k;
        vector<bool>used(n , false);
        sort(nums.rbegin() , nums.rend());
        return solve(nums , used , k , 0 , 0 , target);
    }
};