class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j =0;
        int zero_count = 0;
        int max_len = 0;
        while(j < n){
            if(nums[j] == 0){
                zero_count++;
            }
            while(zero_count > 1){
                if(nums[i] == 0){
                    zero_count--;
                }
                i++;
            }
            max_len = max(max_len , j - i);
            j++;
        }
        return max_len;
    }
};