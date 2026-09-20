class Solution {
public:
    void sortColors(vector<int>& nums) {
         int start = 0;
         int curr = 0;
         int end = nums.size() - 1;
         while(curr <= end){
            if(nums[curr] == 0){
                swap(nums[start] , nums[curr]);
                start++;
                curr++;
            }else if(nums[curr] == 1){
                curr++;
            }else{
                swap(nums[curr] , nums[end]);
                end--;
            }
         }
    }
};