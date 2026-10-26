class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int i = 0;
        int j = 0;
        int count = 0;
        int sum = 0;

        while (j < nums.size()) {
            sum += nums[j];

            while (sum > k) {
                sum -= nums[i];
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};