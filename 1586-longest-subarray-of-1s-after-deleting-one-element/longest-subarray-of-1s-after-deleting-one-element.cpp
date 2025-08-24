class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int i = 0, j = 0;
        int subCount = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }

            subCount = max(subCount, j - i);

            j++;
        }

        return subCount;
    }
};
