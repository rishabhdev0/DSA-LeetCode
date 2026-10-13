class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int taken = n / 2;

        vector<int> absval(n);

        for (int i = 0; i < n; i++) {
            absval[i] = abs(nums[i]);
        }

        sort(absval.begin(), absval.end());

        long long small = 0;
        long long big = 0;

        for (int i = 0; i < taken; i++) {
            small += 1LL * absval[i] * absval[i];
        }

        for (int i = taken; i < n; i++) {
            big += 1LL * absval[i] * absval[i];
        }

        return big - small;
    }
};