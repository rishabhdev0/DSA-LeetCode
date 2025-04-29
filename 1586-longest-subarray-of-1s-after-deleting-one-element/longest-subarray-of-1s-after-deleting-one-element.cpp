class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        int left = 0;
        int zero_count = 0;
        int max_len = 0;
        for(int i = 0 ; i<n;i++){
            if(nums[i]==0){
                zero_count++;
            }

            while(zero_count > 1){
                if(nums[left]==0){
                    zero_count--;
                }
                left++;
            }
            max_len = max(max_len , i-left);
        }
        return max_len;
    }
};