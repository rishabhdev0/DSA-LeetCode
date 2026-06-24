class Solution {
public:
     int count = 0;
     void backtracking(vector<int>& nums , int target , int idx){
         if(idx == nums.size()){
             if(target == 0){
             count++;
            }
            return;
         }

          backtracking(nums , target + nums[idx] , idx + 1);
          backtracking(nums , target - nums[idx] , idx + 1);
     }
    int findTargetSumWays(vector<int>& nums, int target) {
        // i will solve it using backtracking only , it will be TLE but fine;
         backtracking(nums , target , 0);
         return count;
    }
};