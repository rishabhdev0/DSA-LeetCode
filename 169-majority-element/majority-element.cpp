class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
        if (n == 1) return nums[0];
       int count = 0;
       int majority = n/2;
       for(int i = 1; i < n ; i++){
          if(nums[i] == nums[i-1]){
             count++;
             if(count == majority){
                return nums[i];
             }
          } 
          else count = 0;
       }
       return -1;
    }
};