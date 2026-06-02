class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int consecutive_Ones = 0;
        int flipped_zero = 0;
        int j = 0;
        int i = 0;
        while(j < n){
            if(nums[j] == 0){
                flipped_zero++;
            }
            while(flipped_zero > k){
                if(nums[i] == 0){
                    flipped_zero--;
                }
                i++;
            }
            consecutive_Ones = max(consecutive_Ones , j - i + 1);
            j++;
        }
        return consecutive_Ones;
    }
};