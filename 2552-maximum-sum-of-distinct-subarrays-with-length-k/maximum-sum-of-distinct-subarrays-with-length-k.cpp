class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0;
        long long curr_sum = 0;

        unordered_set<int> seen;
        int i = 0;
        int j = 0;
         while(j < n) {

            while (seen.count(nums[j])) {
                curr_sum -= nums[i];
                seen.erase(nums[i]);
                i++;
            }

            seen.insert(nums[j]);
            curr_sum += nums[j];

            if (j - i + 1 > k) {
                curr_sum -= nums[i];
                seen.erase(nums[i]);
                i++;
            }

            if (j - i + 1 == k) {
                max_sum = max(max_sum, curr_sum);
            }
            j++;
        }

        return max_sum;
    }
};