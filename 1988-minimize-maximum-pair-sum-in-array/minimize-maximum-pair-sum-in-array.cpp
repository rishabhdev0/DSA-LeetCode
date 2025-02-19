class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int pair = nums[i] + nums[j];
            if (pair > mini) {
                mini = pair;
            }
        }
        return mini;
    }
};