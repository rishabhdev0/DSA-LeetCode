class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int i = 0;
        int j = 0;
        long long curr_sum = 0;
        long long max_sum = 0;

        while (j < n) {
            freq[nums[j]]++;
            curr_sum += nums[j];

            if (j - i + 1 == k) {
                if (freq.size() == k) {
                    max_sum = max(max_sum, curr_sum);
                }
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                curr_sum -= nums[i];
                i++;
            }
            j++;
        }

        return max_sum;
    }
};
