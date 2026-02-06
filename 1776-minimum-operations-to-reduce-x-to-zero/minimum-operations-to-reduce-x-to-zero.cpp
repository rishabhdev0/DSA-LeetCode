class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int target = total - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int curr_sum = 0;
        int max_len = -1;
        int i = 0;

        for (int j = 0; j < n; j++) {
            curr_sum += nums[j];

            while (curr_sum > target) {
                curr_sum -= nums[i];
                i++;
            }

            if (curr_sum == target) {
                max_len = max(max_len, j - i + 1);
            }
        }

        return max_len == -1 ? -1 : n - max_len;
    }
};
