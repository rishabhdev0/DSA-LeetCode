class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int current = 0;
        int end = n -1 ;
        while(current <= end){
            if(nums[current] == 0){
                swap(nums[start] , nums[current]);
                start++;
                current++;
            }else if(nums[current] == 1){
                current++;
            } else{
                // just swap;
                swap(nums[current] , nums[end]);
                end--;
            }
        }
    }
};