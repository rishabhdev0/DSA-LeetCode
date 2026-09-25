class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long count = 0;

        for(int i = 0; i < n - 1; i++) {
            sum += nums[i];

            long long right_side = total_sum - sum;

            if(sum >= right_side)
                count++;
        }

        return count;
    }
};