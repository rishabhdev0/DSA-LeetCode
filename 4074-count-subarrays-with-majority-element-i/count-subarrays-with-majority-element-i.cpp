class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
       // using brute force , cant find the optimal;
       int count = 0;
       int n = nums.size();
       for(int i = 0 ; i < n ; i++){
          int targetCount = 0;
          int subLen = 0;
          for(int j = i ; j < n ; j++){
            subLen++;
             if(nums[j] == target){
                targetCount++;
             }
             if(targetCount > subLen / 2){
                count++;
             }
          }
       } 
       return count;
    }
};