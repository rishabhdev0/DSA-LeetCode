class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) total_ones++;
        }

        if (total_ones == 0 || total_ones == n) return 0;

        int i = 0, j = 0;
        int curr_ones = 0, max_ones = 0;

        while(j < 2 * n) {
            if(nums[j % n] == 1) curr_ones++;

            if(j - i + 1 > total_ones) {
                if(nums[i % n] == 1) curr_ones--;
                i++;
            }

            if(j - i + 1 == total_ones) {
                max_ones = max(max_ones, curr_ones);
            }

            j++;
        }

        return total_ones - max_ones;
    }
};
