class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;

        long long count = 1;
        int prev = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (prev != -1) {
                    count = (count * (i - prev)) % mod;
                }

                prev = i;
            }
        }

        if (prev == -1) return 0;

        return count;
    }
};