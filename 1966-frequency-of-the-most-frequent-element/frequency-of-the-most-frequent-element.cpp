class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int  n = nums.size();
        sort(nums.begin() , nums.end());
        int i = 0;
        int j = 0;
        int max_freq_len = 1;
        long long sum  = 0;
        while(j < n){
           sum += nums[j];
           while((long long)nums[j] *(j - i + 1) - sum > k){
              sum -= nums[i];
              i++;
           }
           max_freq_len = max(max_freq_len , j - i + 1);
           j++;
        }
        return max_freq_len;
    }
};