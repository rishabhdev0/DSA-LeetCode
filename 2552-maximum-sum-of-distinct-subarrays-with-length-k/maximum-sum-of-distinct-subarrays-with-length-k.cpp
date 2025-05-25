class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long max_sum = 0;
        long long curr_sum = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            curr_sum += nums[j];
            freq[nums[j]]++;

            if (j - i + 1 == k) {
                // Check if all elements are distinct
                if (freq.size() == k) {
                    max_sum = max(max_sum, curr_sum);
                }

                curr_sum -= nums[i];
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }
        }

        return max_sum;
    }
};
