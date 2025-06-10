class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int j = 0;
        long long curr_sum = 0; 
        
        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            int window_size = i - j + 1;
            long long total_needed = 1LL * window_size * nums[i];
            long long ops = total_needed - curr_sum;

            while(ops > k) {
                curr_sum -= nums[j];
                j++;
                ops = (long long)(i - j + 1) * nums[i] - curr_sum;
            }
            
            result = max(result, i - j + 1);
        }
        return result;
    }
};