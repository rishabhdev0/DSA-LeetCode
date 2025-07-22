class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;
        int curr_sum = 0;
        unordered_map<int, int> freq;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            freq[nums[j]]++;
            curr_sum += nums[j];

           //duplicate then shrink the window
            while (freq[nums[j]] > 1) {
                freq[nums[i]]--;
                curr_sum -= nums[i];
                i++;
            }

            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};
