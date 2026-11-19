class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int two_smallest = abs(nums[n-1] - nums[2]);
        int two_biggest = abs(nums[n-3] - nums[0]);
        int one_small_big = abs(nums[n-2] - nums[1]);

        return min({two_smallest, two_biggest, one_small_big});
    }
};