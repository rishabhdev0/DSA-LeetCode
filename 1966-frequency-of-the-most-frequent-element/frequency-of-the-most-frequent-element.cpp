class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int j = 0;
        long long curr_sum = 0; // Use long long for large sum
        
        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            long long ops = (long long)(i - j + 1) * nums[i] - curr_sum; // Ensure this is long long
            
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
