class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       int n = nums.size();
       sort(nums.begin() , nums.end());
       int i = 0;
       int j = 0;
       int max_length = 0;
       while(j < n){
          while(nums[j] - nums[i] >2*k){
            i++;
          }
          j++;
          max_length = max(max_length , j - i );
       } 
       return max_length;
    }
};