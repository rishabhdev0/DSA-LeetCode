class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_length = n + 1;
        int sum = 0;
        int i = 0, j = 0;

        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                min_length = min(min_length, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return (min_length == n + 1) ? 0 : min_length;
    }
};